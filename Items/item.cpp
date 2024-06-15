// Object.cpp
#include "item.h"
#include <GL/freeglut.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>

// Definition of the global objects vector
std::vector<Item> objects;

Item::Item(float x, float z, bool isArrow)
        : x(x), z(z), animationTime(0.0f), isArrow(isArrow) {}

void drawRedArrow(const Item& obj) {
    glColor3f(1.0f, 0.0f, 0.0f);

    float halfBase = ARROW_BASE_SIZE / 2.0f;
    float verticalOffset = FLOAT_HEIGHT * sin(obj.animationTime);

    glBegin(GL_TRIANGLES);

    // Front face
    glVertex3f(obj.x, ARROW_HEIGHT + verticalOffset, obj.z);
    glVertex3f(obj.x - halfBase, verticalOffset, obj.z + halfBase);
    glVertex3f(obj.x + halfBase, verticalOffset, obj.z + halfBase);

    // Right face
    glVertex3f(obj.x, ARROW_HEIGHT + verticalOffset, obj.z);
    glVertex3f(obj.x + halfBase, verticalOffset, obj.z + halfBase);
    glVertex3f(obj.x + halfBase, verticalOffset, obj.z - halfBase);

    // Back face
    glVertex3f(obj.x, ARROW_HEIGHT + verticalOffset, obj.z);
    glVertex3f(obj.x + halfBase, verticalOffset, obj.z - halfBase);
    glVertex3f(obj.x - halfBase, verticalOffset, obj.z - halfBase);

    // Left face
    glVertex3f(obj.x, ARROW_HEIGHT + verticalOffset, obj.z);
    glVertex3f(obj.x - halfBase, verticalOffset, obj.z - halfBase);
    glVertex3f(obj.x - halfBase, verticalOffset, obj.z + halfBase);

    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(obj.x - halfBase, verticalOffset, obj.z + halfBase);
    glVertex3f(obj.x + halfBase, verticalOffset, obj.z + halfBase);
    glVertex3f(obj.x + halfBase, verticalOffset, obj.z - halfBase);
    glVertex3f(obj.x - halfBase, verticalOffset, obj.z - halfBase);
    glEnd();
}

void drawPlusSign(const Item& obj) {
    glColor3f(0.0f, 1.0f, 0.0f);

    glBegin(GL_LINES);

    // X-axis
    glVertex3f(obj.x - PLUS_SIGN_SIZE, 0, obj.z);
    glVertex3f(obj.x + PLUS_SIGN_SIZE, 0, obj.z);

    // Y-axis
    glVertex3f(obj.x, -PLUS_SIGN_SIZE, obj.z);
    glVertex3f(obj.x, PLUS_SIGN_SIZE, obj.z);

    // Z-axis
    glVertex3f(obj.x, 0, obj.z - PLUS_SIGN_SIZE);
    glVertex3f(obj.x, 0, obj.z + PLUS_SIGN_SIZE);

    glEnd();
}

void drawAllObjects(int value) {
    for (const auto& obj : objects) {
        if (obj.isArrow) {
            drawRedArrow(obj);
        } else {
            drawPlusSign(obj);
        }
    }
}

void initializeObjects() {
    srand(static_cast<unsigned>(time(0)));

    // Initialize red arrows
    for (int i = 0; i < 10; ++i) {
        float x = static_cast<float>(rand() % 1001 - 500);
        float z = static_cast<float>(rand() % 1001 - 500);
        objects.emplace_back(x, z, true);
    }

    // Initialize plus signs
    for (int i = 0; i < 10; ++i) {
        float x = static_cast<float>(rand() % 100 - 50);
        float z = static_cast<float>(rand() % 250 - 150);
        objects.emplace_back(x, z, false);
    }
}

void updateAnimation(int value) {
    for (auto& obj : objects) {
        obj.animationTime += 0.03f;
        if (obj.animationTime > 2.0f * 3.14159f) {
            obj.animationTime -= 2.0f * 3.14159f;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, updateAnimation, 0);
}

void updateObjectPositions(int value) {
    for (auto& obj : objects) {
        // Randomly update the position of the object
        obj.x = static_cast<float>(rand() % 100 - 50);
        obj.z = static_cast<float>(rand() % 250 - 150);
    }
    glutTimerFunc(TIME_INTERVAL, updateObjectPositions, 0);
}