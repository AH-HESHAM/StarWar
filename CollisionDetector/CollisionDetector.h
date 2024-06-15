//
// Created by madyelzainy on 6/15/2024.
//

#ifndef STARWAR_COLLISIONDETECTOR_H
#define STARWAR_COLLISIONDETECTOR_H

#include "Object.h"
#include <vector>

class CollisionDetector{

public:
    CollisionDetector()= default;
    int checkSpheresIntersection(float x1, float y1 ,float z1, float r1,float x2, float y2, float z2, float r2);
    void DetectCollision(const std::vector<Object>& objects);
    void HandleCollision(Object first, Object second);
    };


#endif
