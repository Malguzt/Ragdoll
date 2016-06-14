#include "Forearm.h"

Forearm::Forearm(b2World* world, RenderWindow *window, float x, float y): PartOfBody(world, window, x, y)
{
    texture->loadFromFile("img/forearm.png");
    sprite = new Sprite(*texture);
    defineBody(x, y);
    defineSize();
}

Forearm::~Forearm()
{
    //dtor
}

void Forearm::defineBody(float x, float y)
{
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(2.5f, 5.0f);

    createBody(dynamicBox, x, y);
}
