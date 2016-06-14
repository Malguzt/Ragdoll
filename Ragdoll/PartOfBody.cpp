#include "PartOfBody.h"

PartOfBody::PartOfBody(b2World* theWorld, RenderWindow *window, float x, float y)
{
    wnd = window;
    texture = new Texture();
    world = theWorld;
}

PartOfBody::~PartOfBody()
{
    delete texture;
    delete sprite;
}

void PartOfBody::draw()
{
    wnd->draw(*sprite);
}


void PartOfBody::createBody(b2Shape &shape, float x, float y)
{
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(x, y);
    body = world->CreateBody(&bodyDef);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    fixtureDef.density = 10.0f;
    fixtureDef.friction = 0.3f;
    fixtureDef.restitution = 0.5f;
    body->CreateFixture(&fixtureDef);
}

void PartOfBody::updatePosition()
{
    sprite->setPosition(body->GetPosition().x, body->GetPosition().y);
    float32 angle = body->GetAngle() * 180 / 3.14f;
    sprite->setRotation(angle);
}

void PartOfBody::applyForce(b2Vec2 force)
{
    body->SetLinearVelocity(force);
}

void PartOfBody::defineSize()
{
	b2AABB aabb;
	aabb.lowerBound = b2Vec2(FLT_MAX, FLT_MAX);
	aabb.upperBound = b2Vec2(-FLT_MAX, -FLT_MAX);

	for (b2Fixture* f = body->GetFixtureList(); f; f = f->GetNext())
	{
		aabb.Combine(f->GetAABB(0));
	}

	float sizeX = aabb.GetExtents().x*2.0f / sprite->getTexture()->getSize().x;
	float sizeY = aabb.GetExtents().y*2.0f / sprite->getTexture()->getSize().y;
	float originX = sprite->getTexture()->getSize().x / 2.0f;
	float originY = sprite->getTexture()->getSize().y / 2.0f;

	sprite->setScale(sf::Vector2f(sizeX, sizeY));
	sprite->setOrigin(Vector2f(originX, originY));
	sprite->setPosition(body->GetPosition().x, body->GetPosition().y);
}
