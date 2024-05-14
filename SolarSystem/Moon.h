#ifndef MOON_H
#define MOON_H
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "SpaceBody.h"

class Moon : public SpaceBody
{
private:
    SpaceBody *followed;

    void initMoon()
    {
        setInitAngle(followed->getInitAngle());
        setX(followed->getX() + followed->getReduis() + 2);
        setY(followed->getY());
        setZ(followed->getZ());
    }

public:
    Moon(SpaceBody *followed) : SpaceBody(1.0, 1.0, 1.0, 1.0)
    {
        this->followed = followed;
        initMoon();
    }

    void drawBody(float aroundFollowerAngle)
    {
        glColor3f(red, green, blue);
        glPushMatrix();
        glRotatef(aroundFollowerAngle + initAngle, 0, 1, 0);
        glTranslatef(-followed->getX(), 0, 0);
        glRotatef(aroundFollowerAngle * 5, 0, 0, 1);
        glTranslatef(followed->getX(), 0, 0);
        glTranslatef(x, y, -z);
        glutSolidSphere(redius, 50, 50);
        glPopMatrix();
    }
};

#endif