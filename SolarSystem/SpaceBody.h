#ifndef SPACEBODY_H
#define SPACEBODY_H
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "../lib/stb_image.h"

class SpaceBody
{
protected:
    float x = 0.0, y = 0.0, z = 0.0, radius, initAngle = 0.0, red, green, blue;
    GLuint texture;
    bool textureLoaded = false;
public:
    SpaceBody(int radius, float red, float green, float blue)
    {
        this->radius = radius;
        this->red = red;
        this->green = green;
        this->blue = blue;
    }

    virtual Object drawBody(float aroundFollowerAngle, std::string planeName) = 0;

    bool loadTexture(const char* filename) {
        int width, height, nrChannels;
        unsigned char *data = stbi_load(filename, &width, &height, &nrChannels, 0);
        if (!data) {
            std::cerr << "Failed to load texture: " << filename << std::endl;
            return false;
        }

        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        if (nrChannels == 3) {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        } else if (nrChannels == 4) {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        } else {
            std::cerr << "Unsupported number of channels: " << nrChannels << std::endl;
            stbi_image_free(data);
            return false;
        }

        glGenerateMipmap(GL_TEXTURE_2D);
        stbi_image_free(data);

        return true;
    }
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
