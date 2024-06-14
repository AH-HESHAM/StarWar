#ifndef MOON_H
#define MOON_H
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "SpaceBody.h"
#include "../CollisionDetector/Object.h"
#include "../Utility.h"

class Moon : public SpaceBody
{
private:
    SpaceBody *followed;

    void initMoon()
    {
        setInitAngle(followed->getInitAngle());
        setX(followed->getX() + followed->getRadius() + 2);
        setY(followed->getY());
        setZ(followed->getZ());
    }

public:
    Moon(SpaceBody *followed) : SpaceBody(1.0, 1.0, 1.0, 1.0)
    {
        this->followed = followed;
        initMoon();
    }

    Object drawBody(float aroundFollowerAngle)
    {
        glColor3f(red, green, blue);
        GLfloat TransformationMatrix[16];
        glPushMatrix();
        glRotatef(aroundFollowerAngle + initAngle, 0, 1, 0);
        glTranslatef(-followed->getX(), 0, 0);
        glRotatef(aroundFollowerAngle * 5, 0, 0, 1);
        glTranslatef(followed->getX(), 0, 0);
        glTranslatef(x, y, -z);
        glutSolidSphere(radius, 50, 50);
        glGetFloatv(GL_MODELVIEW_MATRIX, TransformationMatrix);
        glPopMatrix();
        return Utility::TransformPoint(radius, TransformationMatrix, "moon");

    }
};

#endif