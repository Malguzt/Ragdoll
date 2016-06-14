#ifndef RAGDOLL_H
#define RAGDOLL_H

#define NUM_OF_PARTS 10
#define HEAD 0
#define BODY 1
#define LEFT_ARM 2
#define RIGHT_ARM 3
#define LEFT_FOREARM 4
#define RIGHT_FOREARM 5
#define LEFT_LEG 6
#define RIGHT_LEG 7
#define LEFT_FOOT 8
#define RIGHT_FOOT 9

#include "PartOfBody.h"

class Ragdoll
{
    public:
        Ragdoll(b2World* world, RenderWindow *window, int x, int y);
        virtual ~Ragdoll();
        void draw();
        void updatePosition();
        void applyForce(float x, float y);
    protected:
    private:
        b2Vec2 shootForce;
        b2World *world;
        RenderWindow *window;
        int numberOfParts = NUM_OF_PARTS;
        PartOfBody* parts[NUM_OF_PARTS];
        void createHeadAndBody(int x, int y);
        void createArms(int x, int y);
        void createLegs(int x, int y);
        void initJointDeff();
        void createJoint(int partA, int partB, b2Vec2 anchorA, b2Vec2 anchorB);
        void createJoint(int partA, int partB, b2Vec2 anchorA, b2Vec2 anchorB, float length);
        void joinParts(b2Body *bodyA, b2Body *bodyB, float x, float y, float angle);
        b2DistanceJointDef* jointDeff;
};

#endif // RAGDOLL_H
