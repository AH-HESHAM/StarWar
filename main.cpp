#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include "SolarSystem/SolarSystem.h"
#include "Views/Views.cpp"
#include "Menu/Menu.h"

void animate(int value);
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
   glewExperimental = GL_TRUE;
   glewInit();
   setup();
   glutMainLoop();
}
