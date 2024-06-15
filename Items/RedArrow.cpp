// #include "RedArrow.h"
// #include <GL/freeglut.h>
// #include <cstdlib>
// #include <ctime>
// #include <iostream>
// #include <cmath>


// static std::vector<std::pair<float, float>> arrowPositions;
// static constexpr float arrowBaseSize = 2.0f;
// static constexpr float arrowHeight = 3.0f;
// static float animationTime = 0.0f;

// void drawRedArrow(float x, float z) {
//     glColor3f(1.0f, 0.0f, 0.0f); // Red color

//     float halfBase = arrowBaseSize / 2.0f;
//     float floatHeight = 0.5f;
//     float verticalOffset = floatHeight * sin(animationTime);

//     glBegin(GL_TRIANGLES);

//     // Front face
//     glVertex3f(x, arrowHeight + verticalOffset, z);            // Apex
//     glVertex3f(x - halfBase, verticalOffset, z + halfBase); // Base vertex 1
//     glVertex3f(x + halfBase, verticalOffset, z + halfBase); // Base vertex 2

//     // Right face
//     glVertex3f(x, arrowHeight + verticalOffset, z);            // Apex
//     glVertex3f(x + halfBase, verticalOffset, z + halfBase); // Base vertex 2
//     glVertex3f(x + halfBase, verticalOffset, z - halfBase); // Base vertex 3

//     // Back face
//     glVertex3f(x, arrowHeight + verticalOffset, z);            // Apex
//     glVertex3f(x + halfBase, verticalOffset, z - halfBase); // Base vertex 3
//     glVertex3f(x - halfBase, verticalOffset, z - halfBase); // Base vertex 4

//     // Left face
//     glVertex3f(x, arrowHeight + verticalOffset, z);            // Apex
//     glVertex3f(x - halfBase, verticalOffset, z - halfBase); // Base vertex 4
//     glVertex3f(x - halfBase, verticalOffset, z + halfBase); // Base vertex 1

//     glEnd();

//     glBegin(GL_QUADS);
//     glVertex3f(x - halfBase, verticalOffset, z + halfBase);
//     glVertex3f(x + halfBase, verticalOffset, z + halfBase);
//     glVertex3f(x + halfBase, verticalOffset, z - halfBase);
//     glVertex3f(x - halfBase, verticalOffset, z - halfBase);
//     glEnd();
// }

// void initializeRedArrows(int numArrows) {
//     srand(static_cast<unsigned>(time(0)));

//     arrowPositions.clear();
//     for (int i = 0; i < numArrows; ++i) {
//         float x = static_cast<float>(rand() % 100 - 50);
//         float z = static_cast<float>(rand() % 250 - 150);
//         arrowPositions.emplace_back(x, z);
//         std::cout << "Red arrow initialized at: (" << x << ", 0, " << z << ")" << std::endl;
//     }
// }

// void updateRedArrows(int value) {
//     for (auto& pos : arrowPositions) {
//         pos.first = static_cast<float>(rand() % 100 - 50);
//         pos.second = static_cast<float>(rand() % 250 - 150);
//         std::cout << "Red arrow updated to: (" << pos.first << ", 0, " << pos.second << ")" << std::endl;
//     }
// }


// void updateAnimation(int value) {
//     animationTime += 0.03f;
//     if (animationTime > 2.0f * 3.14159f) {
//         animationTime -= 2.0f * 3.14159f;
//     }
//     glutPostRedisplay();
//     glutTimerFunc(16, updateAnimation, 0);
// }

// void drawAllRedArrows() {
//     for (const auto& pos : arrowPositions) {
//         drawRedArrow(pos.first, pos.second);
//     }
// }