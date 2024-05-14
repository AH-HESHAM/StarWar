#ifndef SUN_H
#define SUN_H
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "SpaceBody.h"

class Sun : public SpaceBody
{
private:
public:
    Sun() : SpaceBody(6.0, 1.0, 1.0, 0.0) {}

    void drawBody(float aroundFollowerAngle)
    {
        glColor3f(red, green, blue);
        glutSolidSphere(redius, 50, 50);
    }
};

#endif