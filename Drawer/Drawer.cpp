#include "Drawer.h"
#include <GL/freeglut.h>
#include "../Views/Views.h"
#include "../CollisionDetector/CollisionDetector.cpp"
#include "../Projectile/Projectile.h"
#include "../Utility.h"
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
    vector<Object>bodies = solarSystem.drawSolarSystem(sunSpinAngle);
    bodies.push_back(spacecraft.draw());
    double deltaTime = Utility::getCurrentTime() - lastRenderTime;
    lastRenderTime = Utility::getCurrentTime();
    updateProjectiles(deltaTime);
    for(auto it = Utility::projectiles.begin(); it != Utility::projectiles.end(); /* no increment here */) {
        if(it->getLifetime() < 0.0f) {
            it = Utility::projectiles.erase(it);
        } else {
            bodies.push_back(it->render(spacecraft.getX(), spacecraft.getZ(), spacecraft.getAngle()));
            ++it;
        }
    }
    if(isSpacecraftView) {
        DetectCollision(bodies);
    }
}

Drawer Drawer::getInstance() {
    return instance;
}

void Drawer::moveSpacecraft(unsigned char key){
    spacecraft.move(key);
    glutPostRedisplay();
}

void Drawer::updateProjectiles(float deltaTime) {
    for (auto& projectile : Utility::projectiles) {
        projectile.update(deltaTime);
    }
}