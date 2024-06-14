#ifndef VIEWS_H
#define VIEWS_H


#include "../SolarSystem/SolarSystem.h"
#include "../Spacecraft/Spacecraft.h"
#include <functional>

class Views{

public:
    Views() {}
    void topView(const std::function<void(bool)>& gameShow);
    void spaceCraftView(const function<void(bool)> &gameShow, Spacecraft &spacecraft);
};
#endif /* VIEWS_DRAWER_H */