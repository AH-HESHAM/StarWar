// Object.h
#ifndef OBJECT_H
#define OBJECT_H

#include <utility>

class Object {
public:
    Object(float x, float z) : position(x, z), animationTime(0.0f) {}

    virtual ~Object() = default;

    virtual void draw() const = 0;
    virtual void update(float deltaTime) {
        animationTime += deltaTime;
        if (animationTime > 2.0f * 3.14159f) {
            animationTime -= 2.0f * 3.14159f;
        }
    }

    std::pair<float, float> getPosition() const {
        return position;
    }

protected:
    std::pair<float, float> position;
    float animationTime;
};

#endif // OBJECT_H
