#ifndef STARWAR_OBJECT_H
#define STARWAR_OBJECT_H
#include <string>
#include <utility>

class Object {
public:
    // Constructor
    Object(float x, float y, float z, float radius, std::string  type)
            : x(x), y(y), z(z), radius(radius), type(std::move(type)) {}

    // Accessor methods
    float getX() const { return x; }
    float getY() const { return y; }
    float getZ() const { return z; }
    float getRadius() const { return radius; }
    std::string getType() const { return type; }
    int getIndex() const { return index; }
    void setIndex(int newIndex) { index = newIndex; }


private:
    float x;
    float y;
    float z;
    float radius;
    int index;
    std::string type;
};

#endif //STARWAR_OBJECT_H
