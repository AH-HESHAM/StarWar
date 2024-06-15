
#ifndef STARWAR_DRAWER_H
#define STARWAR_DRAWER_H

#include "../Views/Views.h"
#include "../Spacecraft/User.h"
#include "../Spacecraft/Enemy.h"
#include "./Initializer/Initializer.h"
#include "./Timer/Timer.h"

class Drawer {
private:
    Views views;
    double lastRenderTime = Utility::getCurrentTime();
    Timer timer;
    Initializer &initializer;
    std::vector<Enemy> enemies;
    std::function<void(float, float)> endGame;

    Drawer();

    Drawer(const Drawer &) = delete;

    Drawer &operator=(const Drawer &) = delete;


public:
    User userSpacecraft;
    SolarSystem solarSystem;
    static int periodOfTimedActions;

    static Drawer &getInstance();

    static void drawSceneWrapper();

    static void keyboardUpdate(unsigned char key, int x, int y);

    void drawScene();

    void gameShow(bool isSpacecraftView);

    void moveSpacecraft(unsigned char key);

    void drawerInitializer(const std::function<void(float, float)> &endGameCallback);

    vector<Enemy> &getEnemies() { return enemies; }

    void endOfGame();

    void renderBitmapString(float x, float y, void *font, const char *string);

    void drawScoreboard();

    void drawHealthBar(float xOfHealthBar, float yOfHealthBar, float totalLHealthBarWidth, float totalLHealthBarHeight);

    void updateProjectiles(float deltaTime);

    void healthBarHandler();

    void timerShowHandler();

    void killsShowHandler();
};

#endif
