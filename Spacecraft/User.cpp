#include "User.h"
#include "iostream"
#include "GL/glut.h"

float User::getDamage() {
    return damage;
}

void User::move(unsigned char key) {
    switch (key) {
        case 'w':
            moveForward(getDefaultNumberOfUnits());
            std::cout << "Moving forward ('w')" << std::endl;
            break;
        case 's':
            moveBackward(getDefaultNumberOfUnits());
            std::cout << "Moving backward ('s')" << std::endl;
            break;
        case 'a':
            turnLeft(getDefaultNumberOfUnits());
            std::cout << "Turning left ('a')" << std::endl;
            break;
        case 'd':
            turnRight(getDefaultNumberOfUnits());
            std::cout << "Turning right ('d')" << std::endl;
            break;
        default:
            // Handle unrecognized keys if needed
            break;
    }
}

void User::draw() {
    glPushMatrix();
    glTranslatef(x, 0.0f, z);
    glRotatef(-(180 + angle), 0.0f, 1.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f); // Set color to white for the spacecraft

    // Draw the wireframe cone
    glutWireCone(size / 2, size, 5, 10);

    glPopMatrix();
}

void User::increaseScore(float additionalScore) {
    this->score += additionalScore;
}

pair<bool, float> User::decreaseHealth() {
    health -= damage;
    if(isAlive()) return {true, health};

    if(ModeUtility::getMode() == ModeUtility::ChoosenMode::TIMER) respawn();
    return {false, health};
}

void User::respawn() {
    health = getMaxHealth();
    x = initialX;
    z = initialZ;
    angle = initialAngle;
    numberOfRespawns++;
}
