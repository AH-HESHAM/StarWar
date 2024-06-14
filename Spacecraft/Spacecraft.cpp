// Spacecraft.cpp
#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include "Spacecraft.h"
#include "../CollisionDetector/Object.h"
#include "../Utility.h"

using namespace std;

Spacecraft::Spacecraft(float initialX, float initialZ, float initialAngle)
    : x(initialX), z(initialZ), angle(initialAngle), size(10.0f) {
    x = 0.0f;   
    z = 0.0f;
    angle = 0.0f;
}

Object Spacecraft::draw() const {
    glPushMatrix();
    glTranslatef(x, 0.0f, z);
    glRotatef(-(180 + angle), 0.0f, 1.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f); // Set color to white for the spacecraft
    // Draw the wireframe cone
    glutWireCone(size / 2, size, 5, 10);
    glPopMatrix();
    return Object(0.0, 0.0f, -3.5, size/1.7, "spacecraft");
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

double Spacecraft::getZComponentOfViewedPoint(double randomDistance) {
    return z - randomDistance * cos(angle * Utility::PI / 180.0f);
}

double Spacecraft::getXComponentOfViewedPoint(double randomDistance) {
    return x + randomDistance * sin(angle * Utility::PI / 180.0f);
}

void Spacecraft::move(unsigned char key) {
    switch (key) {
        case 'w':
            moveForward(10.0f);
            std::cout << "Moving forward ('w')" << std::endl;
            break;
        case 's':
            moveBackward(10.0f);
            std::cout << "Moving backward ('s')" << std::endl;
            break;
        case 'a':
            turnLeft(10.0f);
            std::cout << "Turning left ('a')" << std::endl;
            break;
        case 'd':
            turnRight(10.0f);
            std::cout << "Turning right ('d')" << std::endl;
            break;
        default:
            // Handle unrecognized keys if needed
            break;
    }
}
