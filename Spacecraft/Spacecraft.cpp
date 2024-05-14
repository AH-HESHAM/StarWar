// Spacecraft.cpp

#include "Spacecraft.h"
#include <GL/glut.h>
#include <cmath>
#include <stdio.h>

using namespace std;

Spacecraft::Spacecraft(float initialX, float initialZ, float initialAngle)
    : x(initialX), z(initialZ), angle(initialAngle), size(100.0f) {
    x = 0.0f;   
    z = 1000.0f;
    angle = 0.0f; 
}

void Spacecraft::draw() const {
    glPushMatrix();
    glTranslatef(x, 0.0f, z);
    glRotatef(angle + 180.0f, 30.0f, -30.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f); // Set color to white for the spacecraft

    // Draw the wireframe cone
    glutWireCone(size / 2, size, 5, 10);

    glPopMatrix();
}

void Spacecraft::turnLeft(float angleIncrement) {
    angle += angleIncrement;
}

void Spacecraft::turnRight(float angleIncrement) {
    angle -= angleIncrement;
}

void Spacecraft::moveForward(float distance) {
    x += distance * sin(angle * 3.14159265359f / 180.0f);
    z -= distance * cos(angle * 3.14159265359f / 180.0f);
}

void Spacecraft::moveBackward(float distance) {
    x -= distance * sin(angle * 3.14159265359f / 180.0f);
    z += distance * cos(angle * 3.14159265359f / 180.0f);
}

void Spacecraft::moveLeft(float distance) {
  x += distance * sin(angle * 3.14159 / 180.0f);  
}

void Spacecraft::moveRight(float distance) {
  x -= distance * sin(angle * 3.14159 / 180.0f);  
}


