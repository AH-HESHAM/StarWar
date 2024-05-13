#ifndef PLANET_H
#define PLANET_H
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "SpaceBody.h"

class Planet : public SpaceBody
{
private:
public:
    Planet(int redius, float red, float green, float blue) : SpaceBody(redius, red, green, blue) {}

    void drawBody(float aroundFollowerAngle)
    {
        glColor3f(red, green, blue);
        glPushMatrix();
        glRotatef(aroundFollowerAngle, 0, 1, 0);
        glRotatef(initAngle, 0, 1, 0);
        glTranslatef(x, y, -z);
        glutSolidSphere(redius, 50, 50);
        glPopMatrix();
    }
};
#endif
