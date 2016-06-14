#include "Head.h"

Head::Head(b2World* world, RenderWindow *window, float x, float y): PartOfBody(world, window, x, y)
{
    texture->loadFromFile("img/head.png");
    sprite = new Sprite(*texture);
    defineBody(x, y);
    defineSize();
}

Head::~Head()
{
}

void Head::defineBody(float x, float y)
{
    b2CircleShape dynamicCircle;
    dynamicCircle.m_radius = 5.0f;

    createBody(dynamicCircle, x, y);
}
