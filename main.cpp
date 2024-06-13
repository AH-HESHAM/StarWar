#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include "SolarSystem/SolarSystem.h"
#include "Views/Views.cpp"
#include "Menu/Menu.h"

void animate(int value);
void keyInput(unsigned char key, int x, int y);
void resize(int w, int h);
void setup(void);
void SelectMode(int mode);

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
      // offset += 0.25;
      glutPostRedisplay();
      break;
   case 'o':
      // offset -= 0.25;
      glutPostRedisplay();
      break;
   case 'w':
      spacecraft.moveForward(10.0f);
      cout << 'w' << endl;
      glutPostRedisplay();
      break;
   case 's':
      spacecraft.moveBackward(10.0f);
      cout << 's' << endl;
      glutPostRedisplay();
      break;
   case 'a':
      spacecraft.moveLeft(10.0f);
      glutPostRedisplay();
      break;
   case 'd':
      spacecraft.moveRight(10.0f);
      glutPostRedisplay();
      break;

   default:
      break;
   }
}

void resize(int w, int h)
{
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();

   glFrustum(Utility::frustumLeft, Utility::frustumRight, Utility::frustumBottom,
             Utility::frustumTop, Utility::frustumZNear, Utility::frustumZFar);

   glMatrixMode(GL_MODELVIEW);
}

void setup(void)
{
   glClearColor(0.0, 0.0, 0.0, 0.0);
   glEnable(GL_DEPTH_TEST);
   animate(1);

   // Turn on OpenGL lighting.
   glEnable(GL_LIGHTING);
   // Light property vectors.
   float lightAmb[] = {0.0, 0.0, 0.0, 1.0};
   float lightDifAndSpec[] = {1.0, 1.0, 1.0, 1.0};
   float globAmb[] = {0.1, 0.1, 0.1, 1.0};
   float lightPos[] = {0, 0, -40 + 14, 1.0};
   // Light properties.
   glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDifAndSpec);
   glLightfv(GL_LIGHT0, GL_SPECULAR, lightDifAndSpec);
   glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
   glEnable(GL_LIGHT0);

   glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globAmb);
   glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);

   float matSpec[] = {1.0, 1.0, 1.0, 1.0};
   float matShine[] = {50.0};

   // Material properties shared by all the spheres.
   glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec);
   glMaterialfv(GL_FRONT, GL_SHININESS, matShine);
   glEnable(GL_CULL_FACE);
   glCullFace(GL_BACK);
   glEnable(GL_COLOR_MATERIAL);
   glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
}

int main(int argc, char **argv)
{
   glutInit(&argc, argv);
   glutInitContextVersion(4, 3);
   glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
   glutInitWindowSize(700, 700);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("Solar system");
   Menu *menu = new Menu(SelectMode, difficultyHandler);
   glutDisplayFunc(showMenu);
   glutReshapeFunc(resize);
   glutKeyboardFunc(keyInput);
   glewExperimental = GL_TRUE;
   glewInit();
   setup();
   glutMainLoop();
}
