#ifndef SPACEBODY_H
#define SPACEBODY_H

#include <GL/glew.h>
#include <GL/freeglut.h>
#include "../lib/getBMP.h"
#include <cmath>

class SpaceBody {
protected:
    float x = 0.0, y = 0.0, z = 0.0, redius, initAngle = 0.0, red, green, blue;
    int p = 20, q = 20; // Number of grid columns and rows.
    float *vertices = nullptr; // Vertex array of the mapped sample on the sphere.
    float *textureCoordinates = nullptr; // Texture co-ordinates array of the mapped sample on the sphere.
    unsigned int texture[1]; // Array of texture indices.

    // Load image as a texture.
    void loadTextures(std::string planetName) {
        imageFile *image[1];
//        image[0] = getBMP("/home/mohamed/CSED_25/Year_3/term_2/Graphics/project/StarWar/Textures/" + planetName + ".bmp");
        image[0] = getBMP("/home/mohamed/CSED_25/Year_3/term_2/Graphics/project/StarWar/Textures/jupiter.bmp");

        glBindTexture(GL_TEXTURE_2D, texture[0]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[0]->width, image[0]->height, 0,
                     GL_RGBA, GL_UNSIGNED_BYTE, image[0]->data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    }

    float x_sphere(int i, int j) {
        return (redius * cos(-M_PI / 2.0 + (float) j / q * M_PI) * cos(2.0 * (float) i / p * M_PI));
    }

    float y_sphere(int i, int j) {
        return (redius * sin(-M_PI / 2.0 + (float) j / q * M_PI));
    }

    float z_sphere(int i, int j) {
        return (-redius * cos(-M_PI / 2.0 + (float) j / q * M_PI) * sin(2.0 * (float) i / p * M_PI));
    }

    // Routine to fill the vertex array with co-ordinates of the mapped sample points.
    void fillVertexArray(void) {
        int i, j, k;

        k = 0;
        for (j = 0; j <= q; j++)
            for (i = 0; i <= p; i++) {
                vertices[k++] = x_sphere(i, j);
                vertices[k++] = y_sphere(i, j);
                vertices[k++] = z_sphere(i, j);
            }
    }

    // Routine to fill the texture co-ordinates array with the texture co-ordinate values at the mapped sample points.
    void fillTextureCoordArray(void) {
        int i, j, k;
        k = 0;
        for (j = 0; j <= q; j++)
            for (i = 0; i <= p; i++) {
                textureCoordinates[k++] = (float) i / p;
                textureCoordinates[k++] = (float) j / q;
            }
    }

    void setup(std::string planetName) {
        // Specify how texture values combine with current surface color values.
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

        // Turn on OpenGL texturing.
        glEnable(GL_TEXTURE_2D);

        // Enable depth testing and the vertex and texture coordinate arrays.
        glEnable(GL_DEPTH_TEST);
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);


        // Create texture ids.
        glGenTextures(1, texture);

        // Load texture.
        loadTextures(planetName);

        // Allocate space for vertex and texture coordinates array.
        vertices = new float[3 * (p + 1) * (q + 1)];
        textureCoordinates = new float[2 * (p + 1) * (q + 1)];

        // Fill the vertex and texture co-ordinates arrays.
        fillVertexArray();
        fillTextureCoordArray();

        // Set the array pointers.
        glVertexPointer(3, GL_FLOAT, 0, vertices);
        glTexCoordPointer(2, GL_FLOAT, 0, textureCoordinates);

        // Cull the back faces of the sphere.
        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);
    }

    void drawSphere(void) {
        int i, j;
        // Check whether the vertices array is initialized
        if (vertices == nullptr) {
            std::cerr << "Error: vertices array is not initialized\n";
            return;
        }
        // Map the texture onto the sphere.
        glBindTexture(GL_TEXTURE_2D, texture[0]);
        for (j = 0; j < q; j++) {
            glBegin(GL_TRIANGLE_STRIP);
            for (i = 0; i <= p; i++) {
                glArrayElement((j + 1) * (p + 1) + i);
                glArrayElement(j * (p + 1) + i);
            }
            glEnd();
        }
    }

public:
    SpaceBody(int redius, float red, float green, float blue) {
        this->redius = redius;
        this->red = red;
        this->green = green;
        this->blue = blue;
        //
        setup("earth");
    }

    virtual void drawBody(float aroundFollowerAngle) = 0;

    void setX(float x) {
        this->x = x;
    }

    void setY(float y) {
        this->y = y;
    }

    void setZ(float z) {
        this->z = z;
    }

    void setInitAngle(float initAngle) {
        this->initAngle = initAngle;
    }

    float getX() {
        return x;
    }

    float getY() {
        return y;
    }

    float getZ() {
        return z;
    }

    float getInitAngle() {
        return initAngle;
    }

    float getReduis() {
        return redius;
    }
};

#endif
