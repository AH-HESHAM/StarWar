#ifndef STARWAR_GAME_H
#define STARWAR_GAME_H

#include <iostream>
using namespace std;

#include "Drawer/Drawer.h"
#include "../SolarSystem/SolarSystem.h"
#include "../Spacecraft/Spacecraft.h"

class Game {
private:
    Drawer drawer;
public:
    Game(): drawer(Drawer::getInstance()) {
        cout << "Game constructor" << endl;
    }
    void startGame();
    void endGame();
};


#endif //STARWAR_GAME_H
