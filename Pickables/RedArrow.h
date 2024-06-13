#ifndef REDARROW_H
#define REDARROW_H

#include <vector>
#include <utility> // For std::pair

// Initializes the red arrow system
void initializeRedArrows(int numArrows);

// Updates red arrow positions
void updateRedArrows(int value);

// Draws all red arrows
void drawAllRedArrows();

// Updates the animation time for floating effect
void updateAnimation(int value);

#endif // REDARROW_H
