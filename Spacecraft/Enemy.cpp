#include "Enemy.h"
#include "../Utility.h"
#include <GL/glut.h>
#include <cmath>


float Enemy::getDamage() {
    return damage;
}

bool Enemy::checkIfUserIsInSight(float userSpacecraftXComponent, float userSpacecraftZComponent) {
    // Check if the user is in sight of the enemy
    float enemySpacecraftXComponent = x;
    float enemySpacecraftZComponent = z;
    float enemyViewedPointXComponent = getXComponentOfViewedPoint(100.0);
    float enemyViewedPointZComponent = getZComponentOfViewedPoint(100.0);

    float term1 = (enemySpacecraftZComponent - enemyViewedPointZComponent) * (enemySpacecraftXComponent - userSpacecraftXComponent);
    float term2 = (enemySpacecraftZComponent - userSpacecraftZComponent) * (enemySpacecraftXComponent - enemyViewedPointXComponent);

    if(std::abs(term1 - term2) < Utility::EPSILON) return true;
    else return false;
}

float Enemy::RotationAngleToFaceUser(float userSpacecraftXComponent, float userSpacecraftZComponent) {
    float newXOfUser = (-userSpacecraftZComponent) - (-z);
    float newYOfUser = (userSpacecraftXComponent) - (x);
    double result = acos(fabs(newXOfUser) / sqrt(pow(newXOfUser, 2) + pow(newYOfUser, 2)));
    result = result * 180 / Utility::PI;
    if(newXOfUser < 0 && newYOfUser > 0) result = 180 - result;
    else if(newXOfUser < 0 && newYOfUser < 0) result = 180 + result;
    else result = 360 - result;
    return result - angle;
}

void Enemy::draw() {
    glPushMatrix();
    glTranslatef(x, 0.0f, z);
    glRotatef(-angle, 0.0f, 1.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    cout << "Enemy: " << x << " " << z << " " << angle << endl;

    // Draw the wireframe cone
    glutSolidCone(size / 2, size, 5, 10);

    glPopMatrix();
}
