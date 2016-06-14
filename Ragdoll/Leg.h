#ifndef LEG_H
#define LEG_H

#include "PartOfBody.h"


class Leg : public PartOfBody
{
    public:
        Leg(b2World* world, RenderWindow *window, float x, float y);
        virtual ~Leg();
    protected:
    private:
        void defineBody(float x, float y);
};

#endif // LEG_H
