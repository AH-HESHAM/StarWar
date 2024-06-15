#include "Game.h"
#include <GL/freeglut.h>
#include "../Drawer/Drawer.cpp"
#include <sstream>
#include <iostream>

void renderBitmapString(float x, float y, void *font, const char *string);
bool Game::gameIsRunning = false;
vector<string> Game::endGameText;
void Game::startGame() {
    gameIsRunning = true;
    drawer.drawerInitializer([this](float score, float spawns) { this->endGame(score, spawns); });
    glutDisplayFunc(Drawer::drawSceneWrapper);
    glutKeyboardFunc(Drawer::keyboardUpdate);
}

void Game::endGame(float score, float spawns) {
    gameIsRunning = false;
    endGameText.emplace_back("Game is over\n");
    endGameText.push_back("Score: " + to_string(score) + "\n");
    if (ModeUtility::isTimerMode())
        endGameText.push_back("Number of respawns: " + to_string(spawns) + "\n");
    endGameText.emplace_back("Press ESC to exit");

    // Set the display function to the end game screen
    glutDisplayFunc(Game::drawEndGameScreen);
    glutPostRedisplay();
}

bool Game::isGameRunning() {
    return gameIsRunning;
}


void Game::drawEndGameScreen() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0, 0, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));

    // Set up orthographic projection for 2D text rendering
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), 0, glutGet(GLUT_WINDOW_HEIGHT));
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    // Push the current color onto the attribute stack
    glPushAttrib(GL_CURRENT_BIT);

    // Set text color
    glColor3f(1.0, 0.0, 1.0);

    // Render text
    float x = 250;
    float y = glutGet(GLUT_WINDOW_HEIGHT) - 250;
    for (const auto &line : endGameText) {
        renderBitmapString(x, y, GLUT_BITMAP_HELVETICA_18, line.c_str());
        y -= 20.0f;
    }

    // Pop the color off the attribute stack
    glPopAttrib();
    glutSwapBuffers();
}

vector<std::string> & Game::getEndGameText() {
    return endGameText;
}

void renderBitmapString(float x, float y, void *font, const char *string) {
    const char *c;
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}
