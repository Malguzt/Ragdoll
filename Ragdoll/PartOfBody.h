#ifndef PARTOFBODY_H
#define PARTOFBODY_H

#include "includes.h"

class PartOfBody
{
    public:
        PartOfBody(b2World* world, RenderWindow *window, float x, float y);
        virtual ~PartOfBody();
        void draw();
        b2Body *body;
        void updatePosition();
        void applyForce(b2Vec2 force);
    protected:
        Texture *texture;
        Sprite *sprite;
        void createBody(b2Shape &shape, float x, float y);
        void defineSize();
    private:
        RenderWindow *wnd;
        b2World *world;
        virtual void defineBody(float x, float y) = 0;
};

#endif // PARTOFBODY_H
