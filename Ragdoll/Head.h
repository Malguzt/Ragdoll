#ifndef HEAD_H
#define HEAD_H
#include "includes.h"
#include "PartOfBody.h"

class Head : public PartOfBody
{
    public:
        Head(b2World* world, RenderWindow *window, float x, float y);
        virtual ~Head();
    protected:
    private:
        void defineBody(float x, float y);
};

#endif // HEAD_H
