// Object.h
#ifndef STARWAR_ITEM_H
#define STARWAR_ITEM_H

#include <vector>
#include <utility>
#include "../CollisionDetector/Object.h"

struct Item {
    float x, z;
    float animationTime;
    bool isArrow; // true for red false for green

    Item(float x, float z, bool isArrow);
};

extern std::vector<Item> objects;
static int TIME_INTERVAL = 100000;

const float ARROW_BASE_SIZE = 2.0f;
const float ARROW_HEIGHT = 3.0f;
const float PLUS_SIGN_SIZE = 2.0f;
const float FLOAT_HEIGHT = 0.5f;

void initializeObjects();
void updateAnimation(int value);
void updateObjectPositions(int value);
std::vector<Object> drawAllObjects(int value, float x, float z, float angle);

#endif // OBJECT_H