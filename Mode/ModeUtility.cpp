#include "ModeUtility.h"

// Initialize static members
int ModeUtility::modeDiff = 0;

std::map<ModeUtility::Difficulty, float> ModeUtility::enemyDamage = {
        {ModeUtility::EASY, 20.0f},
        {ModeUtility::MEDIUM, 30.0f},
        {ModeUtility::HARD, 40.0f}
};

std::map<ModeUtility::Difficulty, int> ModeUtility::numberOfEnemies = {
        {ModeUtility::EASY, 4},
        {ModeUtility::MEDIUM, 8},
        {ModeUtility::HARD, 12}
};

std::map<ModeUtility::Difficulty, int> ModeUtility::gameTimer = {
        {ModeUtility::EASY, 3000 * 60},
        {ModeUtility::MEDIUM, 5000 * 60},
        {ModeUtility::HARD, 10000 * 60}
};

ModeUtility::ChoosenMode ModeUtility::getMode()
{
    if (ModeUtility::modeDiff >= 10)
        return TIMER;
    else
        return SURVIVAL;
}
bool ModeUtility::isSurvivalMode()
{
    return ModeUtility::getMode() == SURVIVAL;
}
bool ModeUtility::isTimerMode()
{
    return ModeUtility::getMode() == TIMER;
}
ModeUtility::Difficulty ModeUtility::getDifficulty()
{
    switch (ModeUtility::modeDiff % 10)
    {
        case 0:
            return EASY;
        case 1:
            return MEDIUM;
        case 2:
            return HARD;
        default:
            return EASY;
    }
}
