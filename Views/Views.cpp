#include <GL/glew.h>
#include <GL/freeglut.h>
#include "../Spacecraft/Spacecraft.h"
#include "../Spacecraft/Spacecraft.cpp"
#include "../Utility.cpp"
#include "Views.h"

float Xangle = 0.0, Yangle = 0.0, Zangle = 0.0, sunSpinAngle = 0.0;
int rotationSpeed = 100;

void Views::topView(const std::function<void(bool)>& gameShow) {
    glLoadIdentity();
    glPushMatrix();
    int lowerPoint = glutGet(GLUT_WINDOW_HEIGHT) * 2 / 3;
    int higherPoint = glutGet(GLUT_WINDOW_HEIGHT) - 10;
    glViewport(lowerPoint, 10,  higherPoint - lowerPoint, higherPoint - lowerPoint);
    gluLookAt(0, 50, -(Utility::frustumZFar + Utility::frustumZNear) / 2,
              0, 49, -(Utility::frustumZFar + Utility::frustumZNear) / 2,
              1, 0, 0);
    gameShow(false);
    glPopMatrix();
}

void Views::spaceCraftView(const std::function<void(bool)>& gameShow, Spacecraft &spacecraft) {
    glLoadIdentity();
    glPushMatrix();
    glViewport(0, 0, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
    double randomDistance = 10.0;
    gluLookAt(spacecraft.getX(), 0, spacecraft.getZ(),
              spacecraft.getXComponentOfViewedPoint(randomDistance), 0, spacecraft.getZComponentOfViewedPoint(randomDistance),
              0, 1, 0);
    gameShow(true);
    glPopMatrix();
}