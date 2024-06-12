// Spacecraft.cpp

#include "Spacecraft.h"
#include "Utility.h"
#include <GL/glut.h>
#include <cmath>
#include <stdio.h>

using namespace std;

Spacecraft::Spacecraft(float initialX, float initialZ, float initialAngle)
    : x(initialX), z(initialZ), angle(initialAngle), size(10.0f) {
    x = 0.0f;   
    z = 0.0f;
    angle = 0.0f;
}

void Spacecraft::draw() const {
    glPushMatrix();
    glTranslatef(x, 0.0f, z);
    glRotatef(-(180 + angle), 0.0f, 1.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f); // Set color to white for the spacecraft

    // Draw the wireframe cone
    glutWireCone(size / 2, size, 5, 10);

    glPopMatrix();
}

void Spacecraft::turnLeft(float angleIncrement) {
    angle -= angleIncrement;
}

void Spacecraft::turnRight(float angleIncrement) {
    angle += angleIncrement;
}

void Spacecraft::moveForward(float distance) {
    x += distance * sin(angle * Utility::PI / 180.0f);
    z -= distance * cos(angle * Utility::PI / 180.0f);
}

void Spacecraft::moveBackward(float distance) {
    x -= distance * sin(angle * Utility::PI / 180.0f);
    z += distance * cos(angle * Utility::PI / 180.0f);
}
