#ifndef SOLARSYSTEM_H
#define SOLARSYSTEM_H
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "Planet.h"
#include "Sun.h"
#include "Moon.h"

class SolarSystem
{
private:
    SpaceBody *planets[8];
    SpaceBody *sun;
    SpaceBody *moon;
    float redius[8] = {1.0, 1.5, 2.0, 2.5, 4.0, 3.0, 3.5, 3.0};
    float red[8] = {241, 165, 0.0, 255.0, 201, 145.0, 13.0, 13.0};
    float green[8] = {184, 46, 0.0, 0.0, 113, 83.0, 156.0, 94.0};
    float blue[8] = {102, 10, 255.0, 0.0, 5.0, 17.0, 213.0, 213.0};
    float zTranslate[8];

    void generateZTranslate()
    {
        zTranslate[0] = 9;
        for (int i = 1; i < 8; i++)
            zTranslate[i] = zTranslate[i - 1] + redius[i] + redius[i - 1] + 2;
    }

    void initSystemItems()
    {
        sun = new Sun();
        for (int i = 0; i < 8; i++)
            planets[i] = new Planet(redius[i], red[i] / 255.0, green[i] / 255.0, blue[i] / 255.0);
    }

    void drawPlanets(float sunSpinAngle)
    {
        int initialAngle = 0;
        for (int j = 7; j >= 0; j--)
        {
            auto planet = planets[j];
            planet->setInitAngle(initialAngle += 100);
            planet->setZ(zTranslate[j]);
            planet->drawBody(sunSpinAngle);
            if (j == 2)
            {
                moon = new Moon(planets[2]);
                moon->drawBody(sunSpinAngle);
            }
        }
    }

public:
    SolarSystem()
    {
        generateZTranslate();
        initSystemItems();
    }

    void drawSolarSystem(float angle)
    {
        sun->drawBody(0.0);
        drawPlanets(angle);
    }
};
#endif
