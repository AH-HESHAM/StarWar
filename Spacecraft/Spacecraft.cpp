// Spacecraft.cpp

#include "Spacecraft.h"
#include "../Utility.h"
#include <GL/glut.h>
#include <cmath>
#include <stdio.h>

using namespace std;

Spacecraft::Spacecraft(float initialX, float initialZ, float initialAngle)
    : x(initialX), z(initialZ), angle(initialAngle), size(30.0f) {
    x = 0.0f;   
    z = 0.0f;
    angle = 0.0f;
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

