// Spacecraft.h

#ifndef SPACECRAFT_H
#define SPACECRAFT_H

class Spacecraft {
public:
    Spacecraft(float initialX, float initialZ, float initialAngle);
    void draw() const;
    void turnLeft(float angleIncrement);
    void turnRight(float angleIncrement);

    void moveForward(float distance);
    void moveBackward(float distance);

    void turnUp(float angleIncrement);
    void turnClockwise(float angleIncrement);

    float getX() const { return x; }
    float getZ() const { return z; }
    float getAngle() const { return angle; }

    
private:
    float x; 
    float z;
    float angle;
    float size;
};

#endif
