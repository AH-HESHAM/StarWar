#include "ModeUtility.h"

int ModeUtility::modeDiff; 

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
