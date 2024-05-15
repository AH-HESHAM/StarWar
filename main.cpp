#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include "SolarSystem/SolarSystem.h"
#include "Views/Views.cpp"

void animate(int value);
void keyInput(unsigned char key, int x, int y);
void resize(int w, int h);
void setup(void);

void animate(int value)
{
   sunSpinAngle += 0.5;
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
      //offset += 0.25;
      glutPostRedisplay();
      break;
   case 'o':
      //offset -= 0.25;
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
    glutDisplayFunc(drawScene);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyInput);
    glewExperimental = GL_TRUE;
    glewInit();
    setup();
    glutMainLoop();
}
