#include <GL/freeglut.h>
#include <GL/glut.h>
#include <iostream>
#include <ostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include "Drawer.h"
#include "../Spacecraft/User.cpp"
#include "../Spacecraft/Enemy.cpp"
#include "../CollisionDetector/CollisionDetector.cpp"
#include "./Initializer/Initializer.cpp"
#include "./Timer/Timer.cpp"
#include "../Items/Item.h"

using namespace std;

int Drawer::periodOfTimedActions = 1000;

Drawer::Drawer():
    initializer(Initializer::getInstance()),
    views(), userSpacecraft(0.0f, 0, 0.0f),
    solarSystem(), timer(), collisionDetector() {}

Drawer& Drawer::getInstance() {
    static Drawer instance;
    return instance;
}

void Drawer::drawerInitializer(const std::function<void(float, float)> &endGameCallback) {
    endGame = endGameCallback;
    timer.startTimer();
    initializer.enemyInitialization();
    initializer.generatePeriodicEnemyAction();
    initializer.timerModeInitializer();
}

void Drawer::drawSceneWrapper() {
    Drawer::getInstance().drawScene();
}

void Drawer::keyboardUpdate(unsigned char key, int x, int y) {
    Drawer::getInstance().moveSpacecraft(key);
}

void Drawer::drawScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLineWidth(2.0);
    this->views.spaceCraftView([this](bool isSpaceCraftView) { gameShow(isSpaceCraftView); }, userSpacecraft);
    drawScoreboard();
    this->views.topView([this](bool isSpaceCraftView) { gameShow(isSpaceCraftView); });
    glutSwapBuffers();
}

void Drawer::gameShow(bool isSpacecraftView) {
    glColor3f(0.0, 0.0, 0.0);
    vector<Object>bodies;
    if(userSpacecraft.isAlive()) {
        bodies.push_back(userSpacecraft.draw());
        for (const auto &planet: solarSystem.drawSolarSystem(sunSpinAngle)) {
            bodies.push_back(planet);
        }
        double deltaTime = Utility::getCurrentTime() - lastRenderTime;
        lastRenderTime = Utility::getCurrentTime();
        updateProjectiles(deltaTime);
        int index  = (int)bodies.size();
        for (auto it = Utility::projectiles.begin(); it != Utility::projectiles.end(); /* no increment here */) {
            if (it->getLifetime() < 0.0f) {
                it = Utility::projectiles.erase(it);
            } else {
                bodies.push_back(it->render(userSpacecraft.getX(), userSpacecraft.getZ(), userSpacecraft.getAngle()));
                ++it;
            }
        }
        for(int i = index ; i < bodies.size() ; i++){
            bodies[i].setIndex(i-index);
        }
        index = (int)bodies.size();
        for (auto &enemy: enemies) {
            if (enemy.isAlive()) {
                bodies.push_back(enemy.draw(userSpacecraft.getX(), userSpacecraft.getZ(), userSpacecraft.getAngle()));
            }
        }
        for(int i = index ; i < bodies.size() ; i++){
            bodies[i].setIndex(i-index);
        }
        for(auto x: drawAllObjects(0, userSpacecraft.getX(), userSpacecraft.getZ(), userSpacecraft.getAngle())){
            bodies.push_back(x);
        }
        if(isSpacecraftView) {
            collisionDetector.DetectCollision(bodies);
        }

    }
    else{
        endOfGame();
    }
}

void Drawer::moveSpacecraft(unsigned char key){
    userSpacecraft.move(key);
    glutPostRedisplay();
}

void Drawer::updateProjectiles(float deltaTime) {
    for (auto& projectile : Utility::projectiles) {
        projectile.update(deltaTime);
    }
}
// in case of timer mode: a call from Initializer::endOfTimedGame()
// in case of survival mode:
//      decrease health has return pair if timer mode visual effect is applied then respawn ***
//      else if survival mode is over: a call to our function
void Drawer::endOfGame() {
    endGame(userSpacecraft.getScore(), userSpacecraft.getNumberOfRespawns());
}

void Drawer::drawScoreboard() {
    // Switch to orthographic projection
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0, glutGet(GLUT_WINDOW_WIDTH), 0, glutGet(GLUT_WINDOW_HEIGHT), -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glDisable(GL_LIGHTING);
    healthBarHandler();
    if (ModeUtility::isTimerMode()) timerShowHandler();
    killsShowHandler();
    // Restore previous projection and model view matrices
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    glEnable(GL_LIGHTING);
}

void Drawer::killsShowHandler() {
    float margin = 10.0f;
    float sizeOfFont = 24.0f;
    glColor3f(1.0f, 1.0f, 1.0f);
    string killedEnemies = "# Killed enemies: " + to_string((int) userSpacecraft.getScore());
    renderBitmapString(glutGet(GLUT_WINDOW_WIDTH) - killedEnemies.size() * (margin + 2), glutGet(GLUT_WINDOW_HEIGHT) - margin * 2 - sizeOfFont, GLUT_BITMAP_TIMES_ROMAN_24, killedEnemies.c_str());
}

void Drawer::timerShowHandler() {
    int elapsedTimeUntilNow = timer.getElapsedTimeUntilNow() / 1000;
    // Convert elapsed time to hh:mm:ss
    int hours = elapsedTimeUntilNow / 3600;
    int minutes = (elapsedTimeUntilNow % 3600) / 60;
    int seconds = elapsedTimeUntilNow % 60;

    // Format the string as hh:mm:ss
    ostringstream oss;
    oss << "Time: " << setw(2) << setfill('0') << hours << ":"
        << setw(2) << setfill('0') << minutes << ":"
        << setw(2) << setfill('0') << seconds;
    string timerText = oss.str();
    int margin = 10;
    int sizeOfFont = 24;
    glColor3f(1.0f, 1.0f, 1.0f);
    renderBitmapString(glutGet(GLUT_WINDOW_WIDTH) / 2 - timerText.size() * margin / 2, glutGet(GLUT_WINDOW_HEIGHT) - margin * 2 - sizeOfFont, GLUT_BITMAP_TIMES_ROMAN_24, timerText.c_str());
}

void Drawer::healthBarHandler() {
    float totalLHealthBarWidth = 200.0f;
    float totalLHealthBarHeight = 20.0f;
    float margin = 10.0f;
    float sizeOfFont = 24.0f;
    glColor3f(1.0f, 1.0f, 1.0f);
    string healthString = "HP:" + to_string((int)round(userSpacecraft.getHealth() / Spacecraft::getMaxHealth() * 100));
    renderBitmapString(10, glutGet(GLUT_WINDOW_HEIGHT) - margin - sizeOfFont, GLUT_BITMAP_TIMES_ROMAN_24, healthString.c_str());
    drawHealthBar(10, glutGet(GLUT_WINDOW_HEIGHT) - margin - sizeOfFont - margin - totalLHealthBarHeight, totalLHealthBarWidth, totalLHealthBarHeight);
}

void Drawer::renderBitmapString(float x, float y, void *font, const char *string) {
    const char *c;
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}


void Drawer::drawHealthBar(float xOfHealthBar, float yOfHealthBar, float totalLHealthBarWidth, float totalLHealthBarHeight) {

    float remainedHealthBarWidth = totalLHealthBarWidth * (userSpacecraft.getHealth() / Spacecraft::getMaxHealth());
    // grey part of health bar
    glColor3f(0.5f, 0.5f, 0.5f);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glLineWidth(5.0);
    glBegin(GL_QUADS);
        glVertex2f(xOfHealthBar + remainedHealthBarWidth, yOfHealthBar);
        glVertex2f(xOfHealthBar + totalLHealthBarWidth, yOfHealthBar);
        glVertex2f(xOfHealthBar + totalLHealthBarWidth, yOfHealthBar + totalLHealthBarHeight);
        glVertex2f(xOfHealthBar + remainedHealthBarWidth, yOfHealthBar + totalLHealthBarHeight);
    glEnd();

    // green part of health bar
    glColor3f(0.f, 1.f, 0.f);
    glBegin(GL_QUADS);
        glVertex2f(xOfHealthBar, yOfHealthBar);
        glVertex2f(xOfHealthBar + remainedHealthBarWidth, yOfHealthBar);
        glVertex2f(xOfHealthBar + remainedHealthBarWidth, yOfHealthBar + totalLHealthBarHeight);
        glVertex2f(xOfHealthBar, yOfHealthBar + totalLHealthBarHeight);
    glEnd();
}
