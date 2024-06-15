#ifndef SOLARSYSTEM_H
#define SOLARSYSTEM_H
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <vector>
#include "../CollisionDetector/Object.h"
#include "Planet.h"
#include "Sun.h"
#include "Moon.h"
#include "../lib/stb_image.h"
#define PATH "/home/mohamed/Graphics_project/StarWar/skybox/"

#
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
        loadSkyboxTextures();
        initSystemItems();
    }

    std::vector<Object> drawSolarSystem(float angle, bool isSpaceCraftView)
    {
        std::vector<Object>SpaceBodies;

        GLfloat TransformationMatrix[16];
        glPushMatrix();
        glTranslatef(0.0, 0.0, offset);

        drawSkybox();


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
    // SkyBox
    GLuint skyboxTextures[6];

    // Skybox texture loading function
    void loadSkyboxTextures() {
        const char* skyboxFaces[6] = {
                "right.png", "left.png", "top.png", "bottom.png", "front.png", "back.png"
        };

        glGenTextures(6, skyboxTextures);

        for (int i = 0; i < 6; i++) {
            int width, height, nrChannels;
            std::string skyboxPath = PATH + std::string(skyboxFaces[i]);
            unsigned char* data = stbi_load(skyboxPath.c_str(), &width, &height, &nrChannels, 0);
            if (data) {
                glBindTexture(GL_TEXTURE_2D, skyboxTextures[i]);
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
                stbi_image_free(data);
            } else {
                printf("Failed to load skybox texture: %s\n", skyboxFaces[i]);
            }
        }
    }

    // Skybox drawing function
    void drawSkybox() {
        float skyboxSize = 75.0f;

        glPushMatrix();
        glDisable(GL_DEPTH_TEST);
        glDepthMask(GL_FALSE);

        // Right face
        glBindTexture(GL_TEXTURE_2D, skyboxTextures[0]);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(skyboxSize, -skyboxSize, -skyboxSize);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(skyboxSize, -skyboxSize, skyboxSize);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(skyboxSize, skyboxSize, skyboxSize);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(skyboxSize, skyboxSize, -skyboxSize);
        glEnd();

        // Left face
        glBindTexture(GL_TEXTURE_2D, skyboxTextures[1]);
        glBegin(GL_QUADS);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-skyboxSize, -skyboxSize, -skyboxSize);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-skyboxSize, skyboxSize, -skyboxSize);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-skyboxSize, skyboxSize, skyboxSize);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-skyboxSize, -skyboxSize, skyboxSize);
        glEnd();

        // Top face
        glBindTexture(GL_TEXTURE_2D, skyboxTextures[2]);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-skyboxSize, skyboxSize, -skyboxSize);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-skyboxSize, skyboxSize, skyboxSize);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(skyboxSize, skyboxSize, skyboxSize);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(skyboxSize, skyboxSize, -skyboxSize);
        glEnd();

        // Bottom face
        glBindTexture(GL_TEXTURE_2D, skyboxTextures[3]);
        glBegin(GL_QUADS);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-skyboxSize, -skyboxSize, -skyboxSize);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(skyboxSize, -skyboxSize, -skyboxSize);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(skyboxSize, -skyboxSize, skyboxSize);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-skyboxSize, -skyboxSize, skyboxSize);
        glEnd();

        // Front face
        glBindTexture(GL_TEXTURE_2D, skyboxTextures[4]);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-skyboxSize, -skyboxSize, skyboxSize);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(skyboxSize, -skyboxSize, skyboxSize);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(skyboxSize, skyboxSize, skyboxSize);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-skyboxSize, skyboxSize, skyboxSize);
        glEnd();

        // Back face
        glBindTexture(GL_TEXTURE_2D, skyboxTextures[5]);
        glBegin(GL_QUADS);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-skyboxSize, -skyboxSize, -skyboxSize);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-skyboxSize, skyboxSize, -skyboxSize);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(skyboxSize, skyboxSize, -skyboxSize);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(skyboxSize, -skyboxSize, -skyboxSize);
        glEnd();

        glDepthMask(GL_TRUE);
        glEnable(GL_DEPTH_TEST);
        glPopMatrix();
    }

};
#endif
