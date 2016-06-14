#ifndef FOOT_H
#define FOOT_H

#include "PartOfBody.h"


class Foot : public PartOfBody
{
    public:
        Foot(b2World* world, RenderWindow *window, float x, float y, char side);
        virtual ~Foot();
    protected:
    private:
        void defineBody(float x, float y);
};

#endif // FOOT_H
