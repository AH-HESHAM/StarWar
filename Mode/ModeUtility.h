#ifndef STARWAR_MODEUTILITY_H
#define STARWAR_MODEUTILITY_H
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

    static int modeDiff;
    static Difficulty getDifficulty();
    static ChoosenMode getMode();
};
#endif