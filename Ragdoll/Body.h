#ifndef BODY_H
#define BODY_H

#include "PartOfBody.h"


class Body : public PartOfBody
{
    public:
        Body(b2World* world, RenderWindow *window, float x, float y);
        virtual ~Body();
    protected:
    private:
        void defineBody(float x, float y);
};

#endif // BODY_H
