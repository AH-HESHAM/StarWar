#include "Game.h"
#include <GL/freeglut.h>
#include "../Drawer/Drawer.cpp"
// needed.
// glutTimerFunc(25, update, 0);


void Game::startGame() {
    drawer.drawerInitializer();
    glutDisplayFunc(Drawer::drawSceneWrapper);
    glutKeyboardFunc(Drawer::keyboardUpdate);
}

void Game::endGame() {

}
