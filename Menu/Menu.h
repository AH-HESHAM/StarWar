#ifndef MENU_H
#define MENU_H
#include <GL/glew.h>
#include <GL/freeglut.h>
// #include "../Mode/ModeUtility.h"
#include "../Mode/ModeUtility.cpp"
#include "../Game/Game.cpp"
#include <iostream>

using namespace std;
class Menu
{
private:
    void (*modeHandler)(int);
    void (*difficultyHandler)(int);

    int makeSubMenu(char op1[], char op2[], char op3[], int base)
    {
        int menu = glutCreateMenu(difficultyHandler);
        glutAddMenuEntry(op1, 0 + base);
        glutAddMenuEntry(op2, 1 + base);
        glutAddMenuEntry(op3, 2 + base);
        return menu;
    }

    void makeMenu()
    {
        char diff1[] = "Easy";
        char diff2[] = "Medium";
        char diff3[] = "Hard";
        int mode1SubMenu = makeSubMenu(diff1, diff2, diff3, 0);
        int mode2SubMenu = makeSubMenu(diff1, diff2, diff3, 10);
        glutCreateMenu(modeHandler);
        glutAddSubMenu("Survive", mode1SubMenu);
        glutAddSubMenu("Timer", mode2SubMenu);
        glutAttachMenu(GLUT_LEFT_BUTTON);
    }

public:
    // static int modeDiff;
    Menu(void (*func)(int), void (*func2)(int))
    {
        modeHandler = func;
        difficultyHandler = func2;
        makeMenu();
    }
};

void showMenu()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    const char *message = "Click inside the window to open the menu";
    glRasterPos3f(-5.0f, 0.0f, -10.0f);
    for (const char *c = message; *c != '\0'; c++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    glutSwapBuffers();
}

void SelectMode(int mode) {
}

void difficultyHandler(int diff)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glutDetachMenu(GLUT_LEFT_BUTTON);
    ModeUtility::modeDiff = diff;
    // game initialization
    Game game;
    game.startGame();
    std::cout<<"Mode"<<ModeUtility::getMode()<<"Diff"<<ModeUtility::getDifficulty();
}

#endif