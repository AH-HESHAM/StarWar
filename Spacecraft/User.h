#ifndef STARWAR_USER_H
#define STARWAR_USER_H

#include "./Spacecraft.h"

class User: public Spacecraft{
private:
    const float damage = 10;
    float score = 0;
    float numberOfRespawns = 0;
public:
    User(float initialX, float initialZ, float initialAngle) : Spacecraft(initialX, initialZ, initialAngle) {};
    float getDamage();
    void move(unsigned char key);
    void draw();
    float getScore() { return score; }
    float getNumberOfRespawns() { return numberOfRespawns; }
    void increaseScore(float score);
    float increaseHealth() { return health += damage; }
    pair<bool, float> decreaseHealth();

    void respawn();
};


#endif //STARWAR_USER_H
