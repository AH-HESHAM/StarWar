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

ModeUtility::ChoosenMode ModeUtility::getMode()
{
    if (ModeUtility::modeDiff >= 10)
        return TIMER;
    else
        return SURVIVAL;
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
