
#ifndef STARWAR_DRAWER_H
#define STARWAR_DRAWER_H
#include "../Views/Views.h"

class Drawer {
private:
    Drawer(): views(), spacecraft(0.0f, 0, 0.0f), solarSystem() {}
    static Drawer instance;
    Views views;

public:
    Spacecraft spacecraft;
    SolarSystem solarSystem;

    static Drawer getInstance();
    static void drawSceneWrapper();
    static void keyboardUpdate(unsigned char key, int x, int y) ;
    void drawScene();
    void gameShow();
    void moveSpacecraft(unsigned char key);
};


#endif
