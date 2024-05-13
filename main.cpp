#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include "SolarSystem/SolarSystem.h"

void drawScene(void);
void animate(int value);
void keyInput(unsigned char key, int x, int y);
void resize(int w, int h);
void setup(void);

float Xangle = 0.0, Yangle = 0.0, Zangle = 0.0, offset = -50, sunSpinAngle = 0.0;
int rotationSpeed = 100;

int main(int argc, char **argv)
{
   glutInit(&argc, argv);
   glutInitContextVersion(4, 3);
   glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
   glutInitWindowSize(700, 700);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("Soalr system");
   glutDisplayFunc(drawScene);
   glutReshapeFunc(resize);
   glutKeyboardFunc(keyInput);
   glewExperimental = GL_TRUE;
   glewInit();
   setup();
   glutMainLoop();
}

void drawScene(void)
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glColor3f(0, 0, 0);
   glPushMatrix();
   glTranslatef(0.0, 0.0, offset);
   glRotatef(Xangle, 1, 0, 0);
   glRotatef(Yangle, 0, 1, 0);
   glRotatef(Zangle, 0, 0, 1);

   SolarSystem *solarSystem = new SolarSystem();
   solarSystem->drawSolarSystem(sunSpinAngle);

   // glBegin(GL_LINES);
   // glVertex3f(-10,0,0);
   // glVertex3f(10,0,0);
   // glColor3f(1,1,1);
   // glVertex3f(0,-10,0);
   // glVertex3f(0,10,0);
   // glColor3f(1,0,0);
   // glVertex3f(0,0,100);
   // glVertex3f(0,0,-100);
   // glEnd();

   glPopMatrix();
   glFlush();
}

void animate(int value)
{
   sunSpinAngle += 1.0;
   if (sunSpinAngle > 360.0)
      sunSpinAngle -= 360.0;
   glutPostRedisplay();
   glutTimerFunc(rotationSpeed, animate, 1);
}

void keyInput(unsigned char key, int x, int y)
{
   switch (key)
   {
   case 'x':
      Xangle += 5.0;
      if (Xangle > 360.0)
         Xangle -= 360.0;
      glutPostRedisplay();
      break;
   case 'X':
      Xangle -= 5.0;
      if (Xangle < 0.0)
         Xangle += 360.0;
      glutPostRedisplay();
      break;
   case 'y':
      Yangle += 5.0;
      if (Yangle > 360.0)
         Yangle -= 360.0;
      glutPostRedisplay();
      break;
   case 'Y':
      Yangle -= 5.0;
      if (Yangle < 0.0)
         Yangle += 360.0;
      glutPostRedisplay();
      break;
   case 'z':
      Zangle += 5.0;
      if (Zangle > 360.0)
         Zangle -= 360.0;
      glutPostRedisplay();
      break;
   case 'Z':
      Zangle -= 5.0;
      if (Zangle < 0.0)
         Zangle += 360.0;
      glutPostRedisplay();
      break;
   case 'O':
      offset += 0.25;
      glutPostRedisplay();
      break;
   case 'o':
      offset -= 0.25;
      glutPostRedisplay();
      break;

   default:
      break;
   }
}

void resize(int w, int h)
{
   glViewport(0, 0, w, h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);
   glMatrixMode(GL_MODELVIEW);
}

void setup(void)
{
   glClearColor(0.0, 0.0, 0.0, 0.0);
   glEnable(GL_DEPTH_TEST);
   animate(1);
}
