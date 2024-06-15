#ifndef STARWAR_INITIALIZER_H
#define STARWAR_INITIALIZER_H


#include "../Drawer.h"

class Initializer {
private:
    Initializer(){};
public:
    static Initializer& getInstance();
    void enemyInitialization();
    void generatePeriodicEnemyAction();
    void timerModeInitializer();
    Initializer(const Initializer&) = delete;
    Initializer& operator = (const Initializer&) = delete;
};


#endif //STARWAR_INITIALIZER_H
