#include "Initializer.h"
#include "Mode/ModeUtility.h"
#include "Drawer/Drawer.h"
#include <vector>

void periodicEnemyOperation(int operationNumber);
void gameTimerGenerator();

Initializer& Initializer::getInstance() {
    static Initializer instance;
    return instance;
}

void Initializer::enemyInitialization() {
    ModeUtility::Difficulty difficulty = ModeUtility::getDifficulty();
    int numberOfEnemiesInGame = ModeUtility::numberOfEnemies[difficulty];
    float enemyDamageInGame = ModeUtility::enemyDamage[difficulty];
    float zLineOfEnemies = -80, angleOfEnemies = 180, betweenTwoEnemiesSpace = 80.0f / ((float)numberOfEnemiesInGame/2.0f);
    std::vector<Enemy> &enemies = Drawer::getInstance().getEnemies();
    for (int i = 1; i <= numberOfEnemiesInGame / 2; i++) {
        enemies.emplace_back(i * betweenTwoEnemiesSpace, zLineOfEnemies, angleOfEnemies, enemyDamageInGame);
    } for (int i = 1; i <= numberOfEnemiesInGame / 2; i++) {
        enemies.emplace_back(-i * betweenTwoEnemiesSpace, zLineOfEnemies, angleOfEnemies, enemyDamageInGame);
    }
}

void Initializer::generatePeriodicEnemyAction() {
    int operationNumber = 0;
    glutTimerFunc(Drawer::periodOfTimedActions, periodicEnemyOperation, operationNumber);
}


void activeEnemiesCommands() {
    for (auto &enemy : Drawer::getInstance().getEnemies()) enemy.operate();
}

void periodicEnemyOperation(int operationNumber) {
    activeEnemiesCommands();
    glutTimerFunc(Drawer::periodOfTimedActions, periodicEnemyOperation, operationNumber + 1);
}

void Initializer::timerModeInitializer() {
    if(ModeUtility::getMode() == ModeUtility::ChoosenMode::TIMER) gameTimerGenerator();
}

void endOfTimedGame(int unused) {

}

void gameTimerGenerator() {
    ModeUtility::Difficulty difficulty = ModeUtility::getDifficulty();
    int timeOfGame = ModeUtility::gameTimer[difficulty];
    glutTimerFunc(timeOfGame, endOfTimedGame, 0);
}
