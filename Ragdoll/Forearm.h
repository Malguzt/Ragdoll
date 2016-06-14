#ifndef FOREARM_H
#define FOREARM_H

#include "PartOfBody.h"


class Forearm : public PartOfBody
{
    public:
        Forearm(b2World* world, RenderWindow *window, float x, float y);
        virtual ~Forearm();
    protected:
    private:
        void defineBody(float x, float y);
};

#endif // FOREARM_H
