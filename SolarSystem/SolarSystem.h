#ifndef SOLARSYSTEM_H
#define SOLARSYSTEM_H
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <vector>
#include "../CollisionDetector/Object.h"
#include "Planet.h"
#include "Sun.h"
#include "Moon.h"

class SolarSystem
{
private:
    SpaceBody *planets[8];
    SpaceBody *sun;
    SpaceBody *moon;
    float Radii[8] = {1.0, 1.5, 2.0, 2.5, 4.0, 3.0, 3.5, 3.0};
    float red[8] = {241, 165, 0.0, 255.0, 201, 145.0, 13.0, 13.0};
    float green[8] = {184, 46, 0.0, 0.0, 113, 83.0, 156.0, 94.0};
    float blue[8] = {102, 10, 255.0, 0.0, 5.0, 17.0, 213.0, 213.0};
    std::string planetsName[8] = {"mercury", "venus", "earth", "mars", "jupiter", "saturn", "uranus", "neptune"};
    float zTranslate[8];
    int offset = -50;

    void generateZTranslate()
    {
        zTranslate[0] = 14;
        for (int i = 1; i < 8; i++)
            zTranslate[i] = zTranslate[i - 1] + Radii[i] + Radii[i - 1] + 2;
    }

    void initSystemItems()
    {
        sun = new Sun();
        for (int i = 0; i < 8; i++)
            planets[i] = new Planet(Radii[i], red[i] / 255.0, green[i] / 255.0, blue[i] / 255.0);
    }

    std::vector<Object> drawPlanets(float sunSpinAngle)
    {
        std::vector<Object>PlanetsAndMoons;
        int initialAngle = 0;
        for (int j = 7; j >= 0; j--)
        {
            std::string planetName = planetsName[j];
            auto planet = planets[j];
            planet->setInitAngle(initialAngle += 100);
            planet->setZ(zTranslate[j]);
            PlanetsAndMoons.push_back(planet->drawBody(sunSpinAngle, planetName));
            if (j == 2)
            {
                moon = new Moon(planets[2]);
                Object moon_object = moon->drawBody(sunSpinAngle, "moon");
                PlanetsAndMoons.push_back(moon_object);
            }
        }
        return PlanetsAndMoons;
    }

public:
    SolarSystem()
    {
        generateZTranslate();
        initSystemItems();
    }

    std::vector<Object> drawSolarSystem(float angle, bool isSpaceCraftView)
    {
        std::vector<Object>SpaceBodies;
        GLfloat TransformationMatrix[16];
        glPushMatrix();
        glTranslatef(0.0, 0.0, offset);
        sun->drawBody(0.0, "sun");
        SpaceBodies = drawPlanets(angle);
        glGetFloatv(GL_MODELVIEW_MATRIX, TransformationMatrix);
        glPopMatrix();
        if(isSpaceCraftView){
            SpaceBodies.push_back(Utility::TransformPoint(sun->getRadius(), TransformationMatrix, "sun"));
            return SpaceBodies;
        }
        return {};
    }
};
#endif
