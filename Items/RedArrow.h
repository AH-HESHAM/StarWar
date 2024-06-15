// // RedArrow.h
// #ifndef STARWAR_REDARROW_H
// #define STARWAR_REDARROW_H

// #include "Object.h"
// #include <GL/freeglut.h>
// #include <cmath>

// class RedArrow : public Object {
// public:
//     RedArrow(float x, float z) : Object(x, z) {}

//     void draw() const override {
//         float arrowBaseSize = 2.0f;
//         float arrowHeight = 3.0f;
//         float floatHeight = 0.5f;
//         float verticalOffset = floatHeight * sin(animationTime);

//         glColor3f(1.0f, 0.0f, 0.0f);
//         float halfBase = arrowBaseSize / 2.0f;

//         glBegin(GL_TRIANGLES);

//         // Front face
//         glVertex3f(position.first, arrowHeight + verticalOffset, position.second);
//         glVertex3f(position.first - halfBase, verticalOffset, position.second + halfBase);
//         glVertex3f(position.first + halfBase, verticalOffset, position.second + halfBase);

//         // Right face
//         glVertex3f(position.first, arrowHeight + verticalOffset, position.second);
//         glVertex3f(position.first + halfBase, verticalOffset, position.second + halfBase);
//         glVertex3f(position.first + halfBase, verticalOffset, position.second - halfBase);

//         // Back face
//         glVertex3f(position.first, arrowHeight + verticalOffset, position.second);
//         glVertex3f(position.first + halfBase, verticalOffset, position.second - halfBase);
//         glVertex3f(position.first - halfBase, verticalOffset, position.second - halfBase);

//         // Left face
//         glVertex3f(position.first, arrowHeight + verticalOffset, position.second);
//         glVertex3f(position.first - halfBase, verticalOffset, position.second - halfBase);
//         glVertex3f(position.first - halfBase, verticalOffset, position.second + halfBase);

//         glEnd();

//         glBegin(GL_QUADS);
//         glVertex3f(position.first - halfBase, verticalOffset, position.second + halfBase);
//         glVertex3f(position.first + halfBase, verticalOffset, position.second + halfBase);
//         glVertex3f(position.first + halfBase, verticalOffset, position.second - halfBase);
//         glVertex3f(position.first - halfBase, verticalOffset, position.second - halfBase);
//         glEnd();
//     }

//     void update(float deltaTime) override {
//         Object::update(deltaTime);
//     }
// };

// #endif // REDARROW_H