// Object.h
#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include <utility>

struct Object {
    float x, z;
    float animationTime;
    bool isArrow; // true for red false for green

    Object(float x, float z, bool isArrow);
};

extern std::vector<Object> objects;
static int TIME_INTERVAL = 10000;

const float ARROW_BASE_SIZE = 2.0f;
const float ARROW_HEIGHT = 3.0f;
const float PLUS_SIGN_SIZE = 2.0f;
const float FLOAT_HEIGHT = 0.5f;

void initializeObjects();
void updateAnimation(int value);
void updateObjectPositions(int value);
void drawAllObjects(int value);

#endif // OBJECT_H
