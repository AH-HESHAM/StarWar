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
     bool inFrontOfEnemy = isInFrontOfEnemy(enemySpacecraftXComponent, enemySpacecraftZComponent,
                              enemyViewedPointXComponent, enemyViewedPointZComponent,
                              userSpacecraftXComponent, userSpacecraftZComponent);
    if(std::abs(term1 - term2) < Utility::EPSILON && inFrontOfEnemy) return true;
    else return false;
}

float Enemy::RotationAngleToFaceUser(float userSpacecraftXComponent, float userSpacecraftZComponent) {
    float newXOfUser = (-userSpacecraftZComponent) - (-z);
    float newYOfUser = (userSpacecraftXComponent) - (x);
    float result = acos(fabs(newXOfUser) / sqrt(pow(newXOfUser, 2) + pow(newYOfUser, 2)));
    result = result * 180 / Utility::PI;
    if(newXOfUser < 0 && newYOfUser > 0) result = 180 - result;
    else if(newXOfUser < 0 && newYOfUser < 0) result = 180 + result;
    else if(newXOfUser > 0 && newYOfUser < 0) result = 360 - result;
    return result - angle;
}

Object Enemy::draw(float userSpacecraftX, float userSpacecraftZ, float userSpacecraftAngle) {
    float cosAngle = cos(userSpacecraftAngle*Utility::PI/180.0f);
    float sinAngle = sin(userSpacecraftAngle*Utility::PI/180.0f);

    glPushMatrix();
    glTranslatef(x, 0.0f, z);
    glRotatef(-(180 + angle), 0.0f, 1.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);

    // Draw the wireframe cone
    glutWireCone(size / 2, size, 5, 10);

    glPopMatrix();
    float reversedX = cosAngle * (x - userSpacecraftX) + sinAngle * (z - userSpacecraftZ);
    float reversedZ = -sinAngle * (x - userSpacecraftX) + cosAngle * (z - userSpacecraftZ);
    return Object(reversedX, 0.0, reversedZ, size/1.7, "enemy");
}

void Enemy::operate() {
    if(!isAlive()) {
        respawnCounter++;
        if(respawnCounter == respawnTicks) respawn(), respawnCounter = 0;
    } else {
        float userSpacecraftXComponent = Drawer::getInstance().userSpacecraft.getX();
        float userSpacecraftZComponent = Drawer::getInstance().userSpacecraft.getZ();
        if(checkIfUserIsInSight(userSpacecraftXComponent, userSpacecraftZComponent)) {
            if(state == MOVE_FORWARD && distanceBetweenEnemyAndUser() > Spacecraft::getMinDistanceBetweenTwoSC()) moveForward(getDefaultNumberOfUnits());
            else {
                shoot(damage, 4.0f);
            }
            switchState();
        } else {
            float angleToRotate = RotationAngleToFaceUser(userSpacecraftXComponent, userSpacecraftZComponent);
            if(angleToRotate < 0) turnLeft(min(-angleToRotate, getDefaultNumberOfUnits()));
            else turnRight(min(angleToRotate, getDefaultNumberOfUnits()));
        }
    }
}

void Enemy::switchState()  {
    state = (state == MOVE_FORWARD) ? ROTATE : MOVE_FORWARD;
}

bool Enemy::isInFrontOfEnemy(float ex, float ez, float vx, float vz, float ux, float uz) {
    float visionX = vx - ex;
    float visionZ = vz - ez;
    float userX = ux - ex;
    float userZ = uz - ez;
    float dotProduct = visionX * userX + visionZ * userZ;
    return dotProduct > 0;
}

float Enemy::decreaseHealth(float inflictedDamage) {
    health -= inflictedDamage;
    return health;
}


void Enemy::respawn() {
    health = getMaxHealth();
    x = initialX;
    z = initialZ;
    angle = initialAngle;
}

float Enemy::distanceBetweenEnemyAndUser() {
    return sqrt(pow(Drawer::getInstance().userSpacecraft.getX() - x, 2) + pow(Drawer::getInstance().userSpacecraft.getZ() - z, 2));
}

