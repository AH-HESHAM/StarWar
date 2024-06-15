#include "Timer.h"

void Timer::startTimer() {
    startTime = std::chrono::steady_clock::now();
}

int Timer::getElapsedTimeUntilNow() {
    auto currentTime = std::chrono::steady_clock::now();
    return (int)std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - startTime).count();
}

void Timer::resetTimer() {
    startTime = std::chrono::steady_clock::now();
}
