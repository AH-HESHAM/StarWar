#include "Utility.h"
const double Utility::frustumLeft = -5.0;
const double Utility::frustumRight = 5.0;
const double Utility::frustumBottom = -5.0;
const double Utility::frustumTop = 5.0;
const double Utility::frustumZNear = 5.0;
const double Utility::frustumZFar = 100.0;
const double Utility::PI = 3.14159265359;
const double Utility::EPSILON = 1e-3;

std::vector<Projectile>Utility::projectiles;

Object Utility::TransformPoint(float x, float y, float z, float radius, const float TransformationMatrix[], const string& type) {

    // The original coordinates
    float original[4] = {x, y, z, 1.0f};

    // Transformed coordinates
    float transformed[4] = {0, 0, 0, 0};

    // Perform matrix multiplication
    for (int i = 0; i < 4; ++i) {
        transformed[i] = 0;
        for (int j = 0; j < 4; ++j) {
            transformed[i] += TransformationMatrix[j * 4 + i] * original[j];  // Correct matrix multiplication order
        }
    }

    return Object(transformed[0], transformed[1], transformed[2], radius, type);
}
double Utility::getCurrentTime() {
    using namespace std::chrono;
    return duration_cast<duration<double>>(steady_clock::now().time_since_epoch()).count();
}
