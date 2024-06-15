#ifndef PLANET_H
#define PLANET_H
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "SpaceBody.h"
#include "../Utility.h"

class Planet : public SpaceBody
{
private:
public:
    Planet(int radius, float red, float green, float blue) : SpaceBody(radius, red, green, blue) {}

    Object drawBody(float aroundFollowerAngle)
    {   GLfloat TransformationMatrix[16];
        glColor3f(red, green, blue);
        glPushMatrix();
        glRotatef(aroundFollowerAngle + initAngle, 0, 1, 0);
        glTranslatef(x, y, -z);
        glutSolidSphere(radius, 50, 50);
        glGetFloatv(GL_MODELVIEW_MATRIX, TransformationMatrix);
        glPopMatrix();
        return Utility::TransformPoint(0.0, 0.0, 0.0, radius, TransformationMatrix, "planet");
    }
};
#endif
