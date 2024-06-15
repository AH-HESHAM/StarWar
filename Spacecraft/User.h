#ifndef STARWAR_USER_H
#define STARWAR_USER_H

#include "./Spacecraft.h"

class User: public Spacecraft{
private:
    float damage = 60.5;
    float score = 0;
    float numberOfRespawns = 0;
public:
    User(float initialX, float initialZ, float initialAngle) : Spacecraft(initialX, initialZ, initialAngle) {};
    float getDamage();
    void move(unsigned char key);
    Object draw();
    float getScore() { return score; }
    float getNumberOfRespawns() { return numberOfRespawns; }
    void increaseScore(float score);
    float increaseHealth() { return health += damage; }
    pair<bool, float> decreaseHealth(float inflictedDamage);
    void setDamage(float inflictedDamage){ damage = inflictedDamage; }

    void respawn();
};


#endif //STARWAR_USER_H
