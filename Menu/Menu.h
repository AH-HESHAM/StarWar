#ifndef MENU_H
#define MENU_H
#include <GL/glew.h>
#include <GL/freeglut.h>
class Menu
{
private:
    void (*modeHandler)(int);

    void makeMenu()
    {
        glutCreateMenu(modeHandler);
        glutAddMenuEntry("Survive", 0);
        glutAddMenuEntry("Timer", 1);
        glutAttachMenu(GLUT_LEFT_BUTTON);
    }

public:
    int mode;
    Menu(void (*func)(int))
    {
        modeHandler = func;
        makeMenu();
    }
};

void showMenu()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0,1.0,1.0,1.0);
    const char *message = "Click inside the window to open the menu";
    glRasterPos3f(-5.0f, 0.0f, -10.0f);
    for (const char *c = message; *c != '\0'; c++) 
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    glutSwapBuffers();
}

#endif