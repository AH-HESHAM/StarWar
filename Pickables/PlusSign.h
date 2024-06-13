// // PlusSign.h
// #ifndef PLUSSIGN_H
// #define PLUSSIGN_H

// #include "Object.h"
// #include <GL/freeglut.h>

// class PlusSign : public Object {
// public:
//     PlusSign(float x, float z) : Object(x, z) {}

//     void draw() const override {
//         float plusSignSize = 2.0f;

//         glColor3f(0.0f, 1.0f, 0.0f);
//         glBegin(GL_LINES);

//         // X-axis
//         glVertex3f(position.first - plusSignSize, 0, position.second);
//         glVertex3f(position.first + plusSignSize, 0, position.second);

//         // Y-axis
//         glVertex3f(position.first, -plusSignSize, position.second);
//         glVertex3f(position.first, plusSignSize, position.second);

//         // Z-axis
//         glVertex3f(position.first, 0, position.second - plusSignSize);
//         glVertex3f(position.first, 0, position.second + plusSignSize);

//         glEnd();
//     }

//     void update(float deltaTime) override {
//         Object::update(deltaTime);
//     }
// };

// #endif // PLUSSIGN_H
