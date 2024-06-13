#include "Drawer.h"
#include "../Views/Views.h"
#include <GL/freeglut.h>
#include <iostream>
#include <vector>

#include "../Spacecraft/User.cpp"
#include "../Spacecraft/Enemy.cpp"

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
    this->views.spaceCraftView([this] { gameShow(); }, userSpacecraft);
    this->views.topView([this] { gameShow(); });
    glutSwapBuffers();
}

void Drawer::gameShow() {
    glColor3f(0.0, 0.0, 0.0);
    solarSystem.drawSolarSystem(sunSpinAngle);
    userSpacecraft.draw();

    for (auto &enemy : enemies) {
        enemy.draw();
    }

}

Drawer Drawer::getInstance() {
    return instance;
}

void Drawer::moveSpacecraft(unsigned char key){
    userSpacecraft.move(key);
    glutPostRedisplay();
}

void Drawer::enemyInitialization() {
    cout << "Enemy Initialization" << endl;
    ModeUtility::Difficulty difficulty = ModeUtility::getDifficulty();
    ModeUtility::ChoosenMode mode = ModeUtility::getMode();
    int numberOfEnemiesInGame = ModeUtility::numberOfEnemies[difficulty];
    float enemyDamageInGame = ModeUtility::enemyDamage[difficulty];
    float zLineOfEnemies = -80, angleOfEnemies = 180, betweenTwoEnemiesSpace = 80.0f / ((float)numberOfEnemiesInGame/2.0f);
    for (int i = 1; i <= numberOfEnemiesInGame / 2; i++) {
        enemies.emplace_back(i * betweenTwoEnemiesSpace, zLineOfEnemies, angleOfEnemies, enemyDamageInGame);
    } for (int i = 1; i <= numberOfEnemiesInGame / 2; i++) {
        enemies.emplace_back(-i * betweenTwoEnemiesSpace, zLineOfEnemies, angleOfEnemies, enemyDamageInGame);
    }
}
