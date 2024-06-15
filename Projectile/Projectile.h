#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <glm/glm.hpp>

class Projectile {
private:
    glm::vec3 position;
    glm::vec3 direction;
    float speed;
    float damage;
    float lifetime;
    bool userProjectile;

public:
    Projectile(glm::vec3 initPosition, glm::vec3 initDirection, float initSpeed, float damage);
    float getSpeed() const {return speed;};
    float getDamage() const {return damage;};
    float getX() const {return position.x;};
    float getZ() const {return position.z;};
    float getLifetime() const {return lifetime;};
    void  deleteProjectile(){lifetime = -1.0;};
    static float getRadius() {return 0.5f;};
    void update(float deltaTime);
    Object render(float x, float z, float angle) const;

};

#endif // PROJECTILE_H
