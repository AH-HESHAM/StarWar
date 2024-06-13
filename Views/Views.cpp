#include <GL/glew.h>
#include <GL/freeglut.h>
#include "../Spacecraft/Spacecraft.h"
#include "../Spacecraft/Spacecraft.cpp"
#include "../Utility.cpp"
#include "../Pickables/PlusSign.h"
#include "../Pickables/PlusSign.cpp"
#include "../SolarSystem/SolarSystem.h"
#include "../Pickables/Object.h"
#include <vector>
#include <memory>

float Xangle = 0.0, Yangle = 0.0, Zangle = 0.0, sunSpinAngle = 0.0;
int rotationSpeed = 100;

SolarSystem solarSystem;
Spacecraft spacecraft(0.0f, 0, 0.0f);


void gameShow();
void spaceCraftView();
void topView();
double getXComponentOfViewedPoint(double randomDistance);
double getZComponentOfViewedPoint(double randomDistance);

void drawScene() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLineWidth(2.0);

    // space-craft view
    spaceCraftView();

    // top view
    topView();

    glutSwapBuffers();

}

void topView() {
    glLoadIdentity();
    int lowerPoint = glutGet(GLUT_WINDOW_HEIGHT) * 2 / 3;
    int higherPoint = glutGet(GLUT_WINDOW_HEIGHT) - 10;
    glViewport(lowerPoint, 10,  higherPoint - lowerPoint, higherPoint - lowerPoint);
    gluLookAt(0, 50, -(Utility::frustumZFar + Utility::frustumZNear) / 2,
              0, 49, -(Utility::frustumZFar + Utility::frustumZNear) / 2,
              1, 0, 0);
    gameShow();
}

void spaceCraftView() {
    glLoadIdentity();
    glViewport(0, 0, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
    double randomDistance = 10.0;
    gluLookAt(spacecraft.getX(), 0, spacecraft.getZ(),
              getXComponentOfViewedPoint(randomDistance), 0, getZComponentOfViewedPoint(randomDistance),
              0, 1, 0);
    gameShow();
}

double getZComponentOfViewedPoint(double randomDistance) {
    return spacecraft.getZ() - randomDistance * cos(spacecraft.getAngle() * Utility::PI / 180.0f);
}

double getXComponentOfViewedPoint(double randomDistance) {
    return spacecraft.getX() + randomDistance * sin(spacecraft.getAngle() * Utility::PI / 180.0f);
}


void gameShow() {
    glColor3f(0.0, 0.0, 0.0);
    solarSystem.drawSolarSystem(sunSpinAngle);
    spacecraft.draw();
    drawAllObjects(0);
}


