#include "Game.h"
#include "../Views/Views.h"
#include <GL/freeglut.h>
#include "Drawer/Drawer.h"
#include "Drawer/Drawer.cpp"
// needed.
// glutTimerFunc(25, update, 0);


void Game::startGame() {
    glutDisplayFunc(Drawer::drawSceneWrapper);
    glutKeyboardFunc(Drawer::keyboardUpdate);
}

void Game::endGame() {

}
