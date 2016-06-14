#include "Foot.h"
using namespace std;

Foot::Foot(b2World* world, RenderWindow *window, float x, float y, char side): PartOfBody(world, window, x, y)
{
    string path = "img/foot .png";
    path[8] = side;
    texture->loadFromFile(path);
    sprite = new Sprite(*texture);
    defineBody(x, y);
    defineSize();
}

Foot::~Foot()
{
    //dtor
}

void Foot::defineBody(float x, float y)
{
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(3.5f, 6.0f);

    createBody(dynamicBox, x, y);
}
