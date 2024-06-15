// Spacecraft.h

#ifndef SPACECRAFT_H
#define SPACECRAFT_H

#include "../Utility.h"

class Spacecraft {
public:
    Spacecraft(float initialX, float initialZ, float initialAngle);

    void turnLeft(float angleIncrement);
    void turnRight(float angleIncrement);

    void moveForward(float distance);
    void moveBackward(float distance);

    double getXComponentOfViewedPoint(double randomDistance);
    double getZComponentOfViewedPoint(double randomDistance);

    float getX() const { return x; }
    float getZ() const { return z; }
    float getAngle() const { return angle; }
    bool isAlive() const { return health > Utility::EPSILON; }
    float getHealth() const { return health; }
    float getDefaultNumberOfUnits() { return DEFAULT_DISTANCE_TO_MOVE; }
    static float getMinDistanceBetweenTwoSC();
    static float getMaxHealth() { return MAX_HEALTH; }
protected:
    float initialX;
    float initialZ;
    float initialAngle;
    float x;
    float z;
    float angle;
    float size;
    float health;
    static const float MAX_HEALTH;
    const float DEFAULT_DISTANCE_TO_MOVE = 10.0f;

    int respawnCounter = 0;
};

#endif
