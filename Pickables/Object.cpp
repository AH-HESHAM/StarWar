#include "Object.h"

Object::Object(float x, float y, float z, int type)
    : x(x), y(y), z(z), type(type) {}

Object::~Object() {}

int Object::getType() const {
    return type;
}
