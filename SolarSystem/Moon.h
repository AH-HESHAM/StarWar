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

    Object drawBody(float aroundFollowerAngle, std::string planeName)
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
//    Object drawBody(float aroundFollowerAngle, std::string planeName)
//    {
//        std::string path = TEXTURE_PATH + planeName + ".bmp";
//        if (!textureLoaded) {
//            if (!loadTexture(path.c_str())) {
//                std::cerr << "Failed to load texture" << std::endl;
//            }
//            textureLoaded = true;
//        }
//        glColor3f(red, green, blue);
//        GLfloat TransformationMatrix[16];
//        glPushMatrix();
//        glRotatef(aroundFollowerAngle + initAngle, 0, 1, 0);
//        glTranslatef(-followed->getX(), 0, 0);
//        glRotatef(aroundFollowerAngle * 5, 0, 0, 1);
//        glTranslatef(followed->getX(), 0, 0);
//        glTranslatef(x, y, -z);
//
//        // Set color to white to avoid tinting the texture
//        glColor3f(1.0f, 1.0f, 1.0f);
//
//        // Enable texturing and bind the texture
//        glEnable(GL_TEXTURE_2D);
//        glBindTexture(GL_TEXTURE_2D, texture);
//
//        // Draw the sphere with texture coordinates
//        GLUquadric *quad = gluNewQuadric();
//        gluQuadricTexture(quad, GL_TRUE);  // Enable texture coordinates generation
//        gluSphere(quad, radius, 50, 50);
//        gluDeleteQuadric(quad);
//
//        glGetFloatv(GL_MODELVIEW_MATRIX, TransformationMatrix);
//        glPopMatrix();
//        glDisable(GL_TEXTURE_2D);  // Disable texturing after drawing
//
//        return Utility::TransformPoint(radius, TransformationMatrix, "moon");
//
//    }
};

#endif