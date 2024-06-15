#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>
#include <iostream>

class Texture {
public:
    GLuint ID;

    Texture(const char* image);
    void bind();
    void unbind();
    void deleteTexture();
};

#endif // TEXTURE_H
