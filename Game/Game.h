#ifndef STARWAR_GAME_H
#define STARWAR_GAME_H

#include <iostream>
using namespace std;

#include "Drawer/Drawer.h"
#include "../SolarSystem/SolarSystem.h"
#include "../Spacecraft/Spacecraft.h"

class Game {
private:
    Drawer &drawer;
    static vector<string> endGameText;
public:
    Game(): drawer(Drawer::getInstance()) {
        cout << "Game constructor" << endl;
    }
    void startGame();
    void endGame(float score, float spawns);

    static bool gameIsRunning;
    static bool isGameRunning();
    static vector<std::string> & getEndGameText();

    static void drawEndGameScreen();

};


#endif //STARWAR_GAME_H
