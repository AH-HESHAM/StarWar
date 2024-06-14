#ifndef SPACEBODY_H
#define SPACEBODY_H
#include <GL/glew.h>
#include <GL/freeglut.h>
class SpaceBody
{
protected:
    float x = 0.0, y = 0.0, z = 0.0, radius, initAngle = 0.0, red, green, blue;

public:
    SpaceBody(int radius, float red, float green, float blue)
    {
        this->radius = radius;
        this->red = red;
        this->green = green;
        this->blue = blue;
    }

    virtual Object drawBody(float aroundFollowerAngle) = 0;

    void setX(float x)
    {
        this->x = x;
    }

    void setY(float y)
    {
        this->y = y;
    }

    void setZ(float z)
    {
        this->z = z;
    }

    void setInitAngle(float initAngle)
    {
        this->initAngle = initAngle;
    }

    float getX()
    {
        return x;
    }

    float getY()
    {
        return y;
    }

    float getZ()
    {
        return z;
    }

    float getInitAngle()
    {
        return initAngle;
    }
    float getRadius()
    {
        return radius;
    }
};
#endif
