#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <cmath>
#include "../SolarSystem/SolarSystem.h"
#include "../Spacecraft/Spacecraft.h"
#include "../Spacecraft/Spacecraft.cpp"

float Xangle = 0.0, Yangle = 0.0, Zangle = 0.0, offset = -200, sunSpinAngle = 0.0;
int rotationSpeed = 100;

Spacecraft spacecraft(0.0f, 0.0f, 0.0f);

void drawTopView(void);

void drawScene(void)
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glColor3f(0, 0, 0);

   // Main Scene
   glViewport(0, 0, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(45.0, (double)glutGet(GLUT_WINDOW_WIDTH) / (double)glutGet(GLUT_WINDOW_HEIGHT), 1.0, 1000.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();

   // Apply camera transformation to follow the spacecraft
    gluLookAt(spacecraft.getX(), 0.0, spacecraft.getZ() + 1.0, 
              spacecraft.getX(), 0, spacecraft.getZ(),         
              0.0, 1.0, 0.0);

   glPushMatrix();
   glTranslatef(0.0, 0.0, offset);
   glRotatef(Xangle, 1, 0, 0);
   glRotatef(Yangle, 0, 1, 0);
   glRotatef(Zangle, 0, 0, 1);

   SolarSystem *solarSystem = new SolarSystem();
   solarSystem->drawSolarSystem(sunSpinAngle);
   glPopMatrix();

   spacecraft.draw();

   // Second Viewport
   drawTopView();

   glutSwapBuffers();
}

void drawTopView(void) {

    int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
    int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);

    int topViewWidth = windowWidth / 3;
    int topViewHeight = windowHeight / 3;
    int topViewX = windowWidth - topViewWidth - 10;
    int topViewY = 10;

    glViewport(topViewX, topViewY, topViewWidth, topViewHeight);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float zoomFactor = 0.15; 
    glOrtho(-500 * zoomFactor, 500 * zoomFactor, -500 * zoomFactor, 500 * zoomFactor, -1000, 1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    float spacecraftX = spacecraft.getX();
    float spacecraftZ = spacecraft.getZ();

    glTranslatef(-spacecraftX * zoomFactor, 0, -spacecraftZ * zoomFactor);
    glRotatef(90, 1, 0, 0); 

    // Draw solar system from the top view
    SolarSystem *solarSystem = new SolarSystem();
    solarSystem->drawSolarSystem(sunSpinAngle);

    glColor3f(1.0, 0.0, 0.0); 
    glPointSize(5.0);
    glBegin(GL_POINTS);
     glVertex2f(spacecraftX * topViewWidth / 1000.0f, spacecraftZ * topViewHeight / 1000.0f);
    glEnd();

    // Draw a rectangle around the top view
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, topViewWidth, 0, topViewHeight); 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(0, 0);
    glVertex2f(topViewWidth, 0);
    glVertex2f(topViewWidth, topViewHeight);
    glVertex2f(0, topViewHeight);
    glEnd();
}
