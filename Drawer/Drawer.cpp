#include "Drawer.h"
#include <GL/freeglut.h>
#include "Views/Views.h"
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
    this->views.spaceCraftView([this] { gameShow(); }, spacecraft);
    this->views.topView([this] { gameShow(); });
    glutSwapBuffers();
}

void Drawer::gameShow() {
    glColor3f(0.0, 0.0, 0.0);
    solarSystem.drawSolarSystem(sunSpinAngle);
    spacecraft.draw();
}

Drawer Drawer::getInstance() {
    return instance;
}

void Drawer::moveSpacecraft(unsigned char key){
    spacecraft.move(key);
    glutPostRedisplay();
}
