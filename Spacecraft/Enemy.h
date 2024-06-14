#ifndef STARWAR_ENEMY_H
#define STARWAR_ENEMY_H

#include "./Spacecraft.h"

class Enemy: public Spacecraft {
private:
    float damage;
    enum State {MOVE_FORWARD, ROTATE};
    State state = MOVE_FORWARD;
    void switchState();
public:

    Enemy(float initialX, float initialZ, float initialAngle, float damage):
        Spacecraft(initialX, initialZ, initialAngle), damage(damage) {}
    float getDamage();
    bool checkIfUserIsInSight(float userSpacecraftXComponent, float userSpacecraftZComponent);
    float RotationAngleToFaceUser(float userSpacecraftXComponent, float userSpacecraftZComponent);
    void draw();
    float increaseHealth() { return health += damage; }
    float decreaseHealth() { return health -= damage; }
    void operate();

    bool isInFrontOfEnemy(float ex, float ez, float vx, float vz, float ux, float uz);
};


#endif //STARWAR_ENEMY_H
