#ifndef STARWAR_TIMER_H
#define STARWAR_TIMER_H

#include <chrono>

class Timer {
private:
    std::chrono::steady_clock::time_point startTime;
public:
    Timer() = default;
    void startTimer();
    int getElapsedTimeUntilNow();
    void resetTimer();
};


#endif //STARWAR_TIMER_H
