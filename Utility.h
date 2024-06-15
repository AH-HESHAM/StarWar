#ifndef STARWAR_UTILITY_H
#define STARWAR_UTILITY_H
#include <string>

class Utility {
public:
    static const double frustumLeft;
    static const double frustumRight;
    static const double frustumBottom;
    static const double frustumTop;
    static const double frustumZNear;
    static const double frustumZFar;
    static const double PI;
    static Object TransformPoint(float x, float y, float z, float radius, const float TransformationMatrix[], const std::string& type);

};


#endif
