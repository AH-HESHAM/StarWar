#ifndef STARWAR_ENEMY_H
#define STARWAR_ENEMY_H

#include "./Spacecraft.h"

class Enemy: public Spacecraft {
private:
    float damage;
public:
    Enemy(float initialX, float initialZ, float initialAngle, float damage):
        Spacecraft(initialX, initialZ, initialAngle), damage(damage) {}

    float getDamage();
    bool checkIfUserIsInSight(float userSpacecraftXComponent, float userSpacecraftZComponent);
    float RotationAngleToFaceUser(float userSpacecraftXComponent, float userSpacecraftZComponent);
    void draw();
};


#endif //STARWAR_ENEMY_H
