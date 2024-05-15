#include <GL/glew.h>
#include <GL/freeglut.h>
#include "../Spacecraft/Spacecraft.h"
#include "../Spacecraft/Spacecraft.cpp"
#include "../Utility.cpp"

float Xangle = 0.0, Yangle = 0.0, Zangle = 0.0, sunSpinAngle = 0.0;
int rotationSpeed = 100;

SolarSystem solarSystem;
Spacecraft spacecraft(0.0f, -20, 0.0f);

void gameShow();
void spaceCraftView();
void topView();

void drawScene(void) {

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
    gluLookAt(0, 0.0, spacecraft.getZ(),
              0, 0, spacecraft.getZ() - 1,
              0.0, 1.0, 0.0);
    gameShow();
}

void gameShow() {
    glColor3f(0.0, 0.0, 0.0);
    solarSystem.drawSolarSystem(sunSpinAngle);
    spacecraft.draw();
}