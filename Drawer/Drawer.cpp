#include "Drawer.h"
#include <GL/freeglut.h>
#include "../Views/Views.h"
#include "../CollisionDetector/CollisionDetector.cpp"
#include <iostream>

using namespace std;

Drawer Drawer::instance;

void Drawer::drawSceneWrapper() {
    Drawer::instance.drawScene();
}

void Drawer::keyboardUpdate(unsigned char key, int x, int y) {
    Drawer::instance.moveSpacecraft(key);
}

void Drawer::drawScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLineWidth(2.0);
    this->views.spaceCraftView([this](bool isSpacecraftView) { gameShow(isSpacecraftView); }, spacecraft);
    this->views.topView([this](bool isSpacecraftView) { gameShow(isSpacecraftView); });

    glutSwapBuffers();
}

void Drawer::gameShow(bool isSpacecraftView) {
    glColor3f(0.0, 0.0, 0.0);
    vector<Object>bodies = solarSystem.drawSolarSystem(sunSpinAngle, isSpacecraftView);
    bodies.push_back(spacecraft.draw());
    DetectCollision(bodies);
}

Drawer Drawer::getInstance() {
    return instance;
}

void Drawer::moveSpacecraft(unsigned char key){
    spacecraft.move(key);
    glutPostRedisplay();
}
