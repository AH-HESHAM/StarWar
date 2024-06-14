
#ifndef STARWAR_DRAWER_H
#define STARWAR_DRAWER_H
#include "../Views/Views.h"
#include "../Spacecraft/User.h"
#include "../Spacecraft/Enemy.h"
#include "Drawer/Initializer/Initializer.h"

class Drawer {
private:
    Views views;
    Initializer &initializer;
    std::vector<Enemy> enemies;

    Drawer();
    Drawer(const Drawer&) = delete;
    Drawer& operator = (const Drawer&) = delete;


public:
    User userSpacecraft;
    SolarSystem solarSystem;
    static int periodOfTimedActions;

    static Drawer& getInstance();
    static void drawSceneWrapper();
    static void keyboardUpdate(unsigned char key, int x, int y) ;
    void drawScene();
    void gameShow();
    void moveSpacecraft(unsigned char key);
    void drawerInitializer();
    vector<Enemy>& getEnemies() { return enemies; }

};
#endif
