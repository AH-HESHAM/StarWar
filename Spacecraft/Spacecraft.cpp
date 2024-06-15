#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include <chrono>
#include "Spacecraft.h"
#include "../Projectile/Projectile.cpp"
#include "../CollisionDetector/Object.h"
#include "../Utility.h"

using namespace std;

Spacecraft::Spacecraft(float initialX, float initialZ, float initialAngle)
        : x(initialX), z(initialZ), angle(initialAngle), size(10.0f), lastRenderTime(0.0), lastShootTime(0.0) {
    x = 0.0f;
    z = 0.0f;
    angle = 0.0f;
}

void Spacecraft::updateProjectiles(float deltaTime) {
    for (auto& projectile : projectiles) {
        projectile.update(deltaTime);
    }
}

double Spacecraft::getCurrentTime() {
    using namespace std::chrono;
    return duration_cast<duration<double>>(steady_clock::now().time_since_epoch()).count();
}

vector<Object> Spacecraft::draw() {
    GLfloat TransformationMatrix[16];
    vector<Object>CraftAndProjectiles;
    glPushMatrix();
    glTranslatef(x, 0.0f, z);
    glRotatef(-(180 + angle), 0.0f, 1.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f); // Set color to white for the spacecraft
    // Draw the wireframe cone
    glGetFloatv(GL_MODELVIEW_MATRIX, TransformationMatrix);
    glutWireCone(size / 2, size, 5, 10);

    glPopMatrix();
    double currentTime = getCurrentTime();
    double deltaTime = currentTime - lastRenderTime;
    lastRenderTime = currentTime;
    updateProjectiles(deltaTime);
    for(auto it = projectiles.begin(); it != projectiles.end();) {
        if(it->getLifetime() <= 0.0f) {
            it = projectiles.erase(it);
        } else {
            CraftAndProjectiles.push_back(it->render(x, z, angle));
            ++it;
        }
    }
    CraftAndProjectiles.emplace_back(0.0, 0.0f, -3.5, size/1.7, "spacecraft");
    return CraftAndProjectiles;
}

void Spacecraft::turnLeft(float angleIncrement) {
    angle -= angleIncrement;
}

void Spacecraft::turnRight(float angleIncrement) {
    angle += angleIncrement;
}

void Spacecraft::moveForward(float distance) {
    x += distance * sin(angle * Utility::PI / 180.0f);
    z -= distance * cos(angle * Utility::PI / 180.0f);
}

void Spacecraft::moveBackward(float distance) {
    x -= distance * sin(angle * Utility::PI / 180.0f);
    z += distance * cos(angle * Utility::PI / 180.0f);
}

double Spacecraft::getZComponentOfViewedPoint(double randomDistance) const {
    return z - randomDistance * cos(angle * Utility::PI / 180.0f);
}

double Spacecraft::getXComponentOfViewedPoint(double randomDistance) const {
    return x + randomDistance * sin(angle * Utility::PI / 180.0f);
}

void Spacecraft::move(unsigned char key) {
    switch (key) {
        case 'w':
            moveForward(10.0f);
            std::cout << "Moving forward ('w')" << std::endl;
            break;
        case 's':
            moveBackward(10.0f);
            std::cout << "Moving backward ('s')" << std::endl;
            break;
        case 'a':
            turnLeft(10.0f);
            std::cout << "Turning left ('a')" << std::endl;
            break;
        case 'd':
            turnRight(10.0f);
            std::cout << "Turning right ('d')" << std::endl;
            break;
        case ' ':
            std::cout << "Firing projectile (' ')" << std::endl;
            shoot();
            break;
        default:
            // Handle unrecognized keys if needed
            break;
    }
}

void Spacecraft::shoot() {
    const float projectileSpeed = 10.0f;
    const float projectileDamage = 10.0f;
    if(getCurrentTime() - lastShootTime > 0.5f){
        lastShootTime = getCurrentTime();
        projectiles.emplace_back(glm::vec3(x, 0.0f, z), glm::vec3(sin(angle * Utility::PI / 180.0f), 0.0f, -cos(angle * Utility::PI / 180.0f)), projectileSpeed, projectileDamage);
        projectiles.back().update(0.7f);
    }
}
