#include "Projectile.h"
#include <GL/glut.h>

// Constructor
Projectile::Projectile(glm::vec3 initPosition, glm::vec3 initDirection, float initSpeed, float initDamage)
        : position(initPosition), direction(initDirection), speed(initSpeed), damage(initDamage) {
    // Ensure movement is only in the X-Z plane
    direction.y = 0.0f;
    direction = glm::normalize(direction); // Normalize the direction vector

    // Calculate the offset based on the spacecraft size
    const float spacecraftSize = 3.5f; // Assuming the spacecraft size used in draw method
    const float offsetDistance = spacecraftSize * 1.1f; // Slightly larger than the spacecraft size to ensure it's outside

    // Offset the initial position slightly in the direction of shooting
    position += direction * offsetDistance;
    lifetime = 5.0f;
}

// Update the projectile's position
void Projectile::update(float deltaTime) {
    position += direction * speed * deltaTime;
    lifetime -= deltaTime;
}

// Render the projectile
Object Projectile::render(float x, float z, float angle) const {
    glPushMatrix();
    glTranslatef(position.x, 0.0, position.z);
    // Set the color to yellow
    glColor3f(1.0f, 1.0f, 0.0f);
    // Draw the projectile as a solid sphere
    glutSolidSphere(0.5, 10, 10);
    glPopMatrix();
    float cosAngle = cos(angle*Utility::PI/180.0f);
    float sinAngle = sin(angle*Utility::PI/180.0f);

    float reversedX = cosAngle * (position.x - x) + sinAngle * (position.z - z);
    float reversedZ = -sinAngle * (position.x - x) + cosAngle * (position.z - z);
    return Object(reversedX, 0.0f, reversedZ, 0.5f, "projectile");
}
