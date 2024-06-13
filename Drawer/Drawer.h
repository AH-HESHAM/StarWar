
#ifndef STARWAR_DRAWER_H
#define STARWAR_DRAWER_H
#include "../Views/Views.h"
#include "../Spacecraft/User.h"
#include "../Spacecraft/Enemy.h"

class Drawer {
private:
    Drawer(): views(), userSpacecraft(0.0f, 0, 0.0f), solarSystem() {
        enemyInitialization();
    }
    static Drawer instance;
    Views views;
    std::vector<Enemy> enemies;

public:
    User userSpacecraft;
    SolarSystem solarSystem;

    void enemyInitialization();
    static Drawer getInstance();
    static void drawSceneWrapper();
    static void keyboardUpdate(unsigned char key, int x, int y) ;
    void drawScene();
    void gameShow();
    void moveSpacecraft(unsigned char key);
};


#endif
