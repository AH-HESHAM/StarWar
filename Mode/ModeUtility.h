#ifndef STARWAR_MODEUTILITY_H
#define STARWAR_MODEUTILITY_H

#include <map>

class ModeUtility
{
public:
    enum ChoosenMode
    {
        SURVIVAL,
        TIMER
    };
    enum Difficulty
    {
        EASY,
        MEDIUM,
        HARD
    };

    static std::map<Difficulty, float> enemyDamage;
    static std::map<Difficulty, int> numberOfEnemies;

    static int modeDiff;
    static Difficulty getDifficulty();
    static ChoosenMode getMode();
};

#endif // STARWAR_MODEUTILITY_H
