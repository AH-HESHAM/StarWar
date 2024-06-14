//
// Created by madyelzainy on 6/14/2024.
//

#ifndef STARWAR_OBJECT_H
#define STARWAR_OBJECT_H
#include <string>

class Object {
public:
    // Constructor
    Object(float x, float y, float z, float radius, const std::string& type)
            : x(x), y(y), z(z), radius(radius), type(type) {}

    // Accessor methods
    float getX() const { return x; }
    float getY() const { return y; }
    float getZ() const { return z; }
    float getRadius() const { return radius; }
    std::string getType() const { return type; }
    void setRadius(float x) { this->x = x; }
    void setType(float x) { this->x = x; }


private:
    float x;
    float y;
    float z;
    float radius;
    std::string type;
};

#endif //STARWAR_OBJECT_H
