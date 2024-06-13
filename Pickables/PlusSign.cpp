// #include "PlusSign.h"
// #include <GL/glew.h>
// #include <cstdlib>
// #include <ctime>
// #include <iostream> 
// #include <cmath>
// #include <GL/freeglut.h>

// static std::vector<std::pair<float, float>> plusSigns;
// static float plusSignSize = 2.0f;
// static float plusSignAnimationTime = 0.0f;
// static constexpr float floatHeight = 0.5f; 

// const int TIMER_INTERVAL = 15000; 

// void drawPlusSign(float x, float y, float z) {
//     glColor3f(0.0f, 1.0f, 0.0f); 
//     glBegin(GL_LINES);

//     // X-axis
//     glVertex3f(x - plusSignSize, y, z);
//     glVertex3f(x + plusSignSize, y, z);

//     // Y-axis
//     glVertex3f(x, y - plusSignSize, z);
//     glVertex3f(x, y + plusSignSize, z);

//     // Z-axis
//     glVertex3f(x, y, z - plusSignSize);
//     glVertex3f(x, y, z + plusSignSize);

//     glEnd();
// }


// void initializePlusSigns(int numSigns) {
//     srand(static_cast<unsigned>(time(0))); 

//     plusSigns.clear(); // Clear existing plus signs
//     for (int i = 0; i < numSigns; ++i) {
//         float x = static_cast<float>(rand() % 100 - 40); 
//         float z = static_cast<float>(rand() % 250 - 150); 
//         plusSigns.emplace_back(x, z);
//         std::cout << "Plus sign initialized at: (" << x << ", 0, " << z << ")" << std::endl;
//     }
// }

// // Function to update plus sign positions randomly
// void updatePlusSigns(int value) {
//     for (auto& pos : plusSigns) {
//         pos.first = static_cast<float>(rand() % 100 - 40); 
//         pos.second = static_cast<float>(rand() % 250 - 150); 
//         std::cout << "Plus sign updated to: (" << pos.first << ", 0, " << pos.second << ")" << std::endl; 
//     }
//     glutPostRedisplay(); 
//     glutTimerFunc(TIMER_INTERVAL, updatePlusSigns, 0);
// }

// // Function to update the animation time for floating effect
// void updatePlusSignAnimation(int value) {
//     plusSignAnimationTime += 0.03f; 
//     if (plusSignAnimationTime > 2.0f * 3.14159f) { 
//         plusSignAnimationTime -= 2.0f * 3.14159f;
//     }
//     glutPostRedisplay(); // Trigger redisplay
//     glutTimerFunc(16, updatePlusSignAnimation, 0); 
// }


// void drawAllPlusSigns() {
//     float verticalOffset = floatHeight * sin(plusSignAnimationTime);
//     for (const auto& pos : plusSigns) {
//         drawPlusSign(pos.first, verticalOffset, pos.second); 
//     }
// }
