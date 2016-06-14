#include "Body.h"

Body::Body(b2World* world, RenderWindow *window, float x, float y): PartOfBody(world, window, x, y)
{
    texture->loadFromFile("img/body.png");
    sprite = new Sprite(*texture);
    defineBody(x, y);
    defineSize();
}

Body::~Body()
{
    //dtor
}

void Body::defineBody(float x, float y)
{
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(10.0f, 10.0f);

    createBody(dynamicBox, x, y);
}

