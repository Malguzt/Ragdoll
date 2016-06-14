#include "Leg.h"

Leg::Leg(b2World* world, RenderWindow *window, float x, float y): PartOfBody(world, window, x, y)
{
    texture->loadFromFile("img/leg.png");
    sprite = new Sprite(*texture);
    defineBody(x, y);
    defineSize();
}

Leg::~Leg()
{
}

void Leg::defineBody(float x, float y)
{
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(3.0f, 6.0f);

    createBody(dynamicBox, x, y);
}
