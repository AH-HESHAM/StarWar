#include "../Projectile/Projectile.h"
#include <vector>
#ifndef SPACECRAFT_H
#define SPACECRAFT_H
class Spacecraft {
private:
    float x, z, angle, size;
    std::vector<Projectile> projectiles;
    double lastRenderTime;
    double lastShootTime;

public:
    Spacecraft(float initialX, float initialZ, float initialAngle);
    void updateProjectiles(float deltaTime);
    std::vector<Object> draw(); // Removing const to allow updating lastRenderTime
    void turnLeft(float angleIncrement);
    void turnRight(float angleIncrement);
    void moveForward(float distance);
    void moveBackward(float distance);
    double getZComponentOfViewedPoint(double randomDistance) const;
    double getXComponentOfViewedPoint(double randomDistance) const;
    void move(unsigned char key);
    void shoot();
    float getX() const { return x; }
    float getZ() const { return z; }
    float getAngle() const { return angle; }
    static double getCurrentTime() ; // Function to get the current time in seconds
    std::vector<Projectile> getProjectiles() const { return projectiles; }
    double getLastRenderTime() const { return lastRenderTime; }
    void setLastRenderTime(double time) { lastRenderTime = time;}
};

#endif
