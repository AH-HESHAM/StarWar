#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include <chrono>
#include "Spacecraft.h"
#include "../Projectile/Projectile.cpp"
#include "../CollisionDetector/Object.h"
#include "../Utility.h"

using namespace std;

const float Spacecraft::MAX_HEALTH = 120;

Spacecraft::Spacecraft(float initialX, float initialZ, float initialAngle)
    : x(initialX), z(initialZ), angle(initialAngle), size(10.0f), lastShootTime(Utility::getCurrentTime()) {
    x = this->initialX = initialX;
    z = this->initialZ = initialZ;
    angle = this->initialAngle = initialAngle;
    health = MAX_HEALTH;
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

double Spacecraft::getZComponentOfViewedPoint(double randomDistance) {
    return z - randomDistance * cos(angle * Utility::PI / 180.0f);
}

double Spacecraft::getXComponentOfViewedPoint(double randomDistance) {
    return x + randomDistance * sin(angle * Utility::PI / 180.0f);
}

float Spacecraft::getMinDistanceBetweenTwoSC() {
    return 50.0f;
}

void Spacecraft::shoot(float projectileDamage, float timeBetweenShots) {
    const float projectileSpeed = 10.0f;
    if(Utility::getCurrentTime() - lastShootTime > timeBetweenShots){
        lastShootTime = Utility::getCurrentTime();
        Utility::projectiles.emplace_back(glm::vec3(x, 0.0f, z), glm::vec3(sin(angle * Utility::PI / 180.0f), 0.0f, -cos(angle * Utility::PI / 180.0f)), projectileSpeed, projectileDamage);
        Utility::projectiles.back().update(0.7f);
    }
}
