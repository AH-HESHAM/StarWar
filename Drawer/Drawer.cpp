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

//void Drawer::enemyInitialization() {
//    ModeUtility::Difficulty difficulty = ModeUtility::getDifficulty();
//    int numberOfEnemiesInGame = ModeUtility::numberOfEnemies[difficulty];
//    float enemyDamageInGame = ModeUtility::enemyDamage[difficulty];
//    float zLineOfEnemies = -80, angleOfEnemies = 180, betweenTwoEnemiesSpace = 80.0f / ((float)numberOfEnemiesInGame/2.0f);
//    for (int i = 1; i <= numberOfEnemiesInGame / 2; i++) {
//        enemies.emplace_back(i * betweenTwoEnemiesSpace, zLineOfEnemies, angleOfEnemies, enemyDamageInGame);
//    } for (int i = 1; i <= numberOfEnemiesInGame / 2; i++) {
//        enemies.emplace_back(-i * betweenTwoEnemiesSpace, zLineOfEnemies, angleOfEnemies, enemyDamageInGame);
//    }
//}
//void activeEnemiesCommands() {
//    // add counter to for loop
//    int ct = 0;
//    for (auto &enemy : Drawer::getInstance().getEnemies()) {
//        enemy.operate(ct);
//        ct++;
//    }
//}
//
//void periodicEnemyOperation(int operationNumber) {
//    activeEnemiesCommands();
//    glutTimerFunc(Drawer::periodOfTimedActions, periodicEnemyOperation, operationNumber + 1);
//}
//
//void Drawer::generatePeriodicEnemyAction() {
//    int operationNumber = 0;
//    glutTimerFunc(Drawer::periodOfTimedActions, periodicEnemyOperation, operationNumber);
//}

void Drawer::drawerInitializer() {
    cout << "Drawer Initializer" << endl;
    initializer.enemyInitialization();
    cout << "Enemy initialization" << endl;
    initializer.generatePeriodicEnemyAction();
    initializer.timerModeInitializer();
//
//    enemyInitialization();
//    generatePeriodicEnemyAction();
//    if(ModeUtility::getMode() == ModeUtility::ChoosenMode::TIMER) gameTimerGenerator();
}

//void endOfTimedGame(int unused) {
//
//}
//void Drawer::gameTimerGenerator() {
//    ModeUtility::Difficulty difficulty = ModeUtility::getDifficulty();
//    int timeOfGame = ModeUtility::gameTimer[difficulty];
//    glutTimerFunc(timeOfGame, endOfTimedGame, 0);
//}
