#ifndef PLANET_H
#define PLANET_H
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "SpaceBody.h"
#include "../Utility.h"
#include <cmath>

# define TEXTURE_PATH "C:/Users/madyelzainy/OneDrive/Desktop/lastisa/StarWar/Textures/"
class Planet : public SpaceBody
{
private:
public:
    Planet(int radius, float red, float green, float blue) : SpaceBody(radius, red, green, blue) {}

    // Function to draw the textured sphere
    Object drawBody(float aroundFollowerAngle, std::string planeName) {
        std::string path = TEXTURE_PATH + planeName + ".bmp";
        if (!textureLoaded) {
            if (!loadTexture(path.c_str())) {
                std::cerr << "Failed to load texture" << std::endl;
            }
            textureLoaded = true;
        }

        GLfloat TransformationMatrix[16];
        glPushMatrix();
        glRotatef(aroundFollowerAngle + initAngle, 0, 1, 0);
        glTranslatef(x, y, -z);

        // Set color to white to avoid tinting the texture
        glColor3f(1.0f, 1.0f, 1.0f);

        // Enable texturing and bind the texture
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture);

        // Draw the sphere with texture coordinates
        GLUquadric *quad = gluNewQuadric();
        gluQuadricTexture(quad, GL_TRUE);  // Enable texture coordinates generation
        gluSphere(quad, radius, 50, 50);
        gluDeleteQuadric(quad);

        glGetFloatv(GL_MODELVIEW_MATRIX, TransformationMatrix);
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);  // Disable texturing after drawing

        return Utility::TransformPoint(0.0, 0.0, 0.0, radius, TransformationMatrix, "planet");
    }

};
#endif
