#include "Drawer.h"
#include "../Views/Views.h"
#include <GL/freeglut.h>
#include <iostream>
#include <vector>

#include "../Spacecraft/User.cpp"
#include "../Spacecraft/Enemy.cpp"
#include "Drawer/Initializer/Initializer.h"
#include "Drawer/Initializer/Initializer.cpp"

using namespace std;

int Drawer::periodOfTimedActions = 1000;

Drawer::Drawer(): initializer(Initializer::getInstance()), views(), userSpacecraft(0.0f, 0, 0.0f), solarSystem() {}

void Drawer::drawSceneWrapper() {
    Drawer::getInstance().drawScene();
}

void Drawer::keyboardUpdate(unsigned char key, int x, int y) {
    Drawer::getInstance().moveSpacecraft(key);
}

void Drawer::drawScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLineWidth(2.0);
    this->views.spaceCraftView([this] { gameShow(); }, userSpacecraft);
    this->views.topView([this] { gameShow(); });
    glutSwapBuffers();
}

void Drawer::gameShow() {
    glColor3f(0.0, 0.0, 0.0);
    solarSystem.drawSolarSystem(sunSpinAngle);
    userSpacecraft.draw();

    for (auto &enemy : enemies) {
        if(enemy.isAlive()) enemy.draw();
    }
}

Drawer& Drawer::getInstance() {
    static Drawer instance;
    return instance;
}

void Drawer::moveSpacecraft(unsigned char key){
    userSpacecraft.move(key);
    glutPostRedisplay();
}

void Drawer::drawerInitializer() {
    cout << "Drawer Initializer" << endl;
    initializer.enemyInitialization();
    cout << "Enemy initialization" << endl;
    initializer.generatePeriodicEnemyAction();
    initializer.timerModeInitializer();
}
