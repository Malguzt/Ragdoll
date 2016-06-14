#ifndef ARM_H
#define ARM_H

#include "PartOfBody.h"


class Arm : public PartOfBody
{
    public:
        Arm(b2World* world, RenderWindow *window, float x, float y);
        virtual ~Arm();
    protected:
    private:
        void defineBody(float x, float y);
};

#endif // ARM_H
