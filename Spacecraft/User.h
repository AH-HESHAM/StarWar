#ifndef STARWAR_USER_H
#define STARWAR_USER_H

#include "./Spacecraft.h"

class User: public Spacecraft{
private:
    const float damage = 10;
public:
    User(float initialX, float initialZ, float initialAngle) : Spacecraft(initialX, initialZ, initialAngle) {};
    float getDamage();
    void move(unsigned char key);
    void draw();
};


#endif //STARWAR_USER_H
