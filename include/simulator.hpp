#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP

#include <random>
#include <iostream>
#include "parameters.hpp"
#include <cmath>

class Simulator {
public:
    Simulator();
    ~Simulator();
    double generateUserAppearanceTime(double t_lambda);
    void updateSimulatorTime(double t_updateTime);
    double m_simulatorTime;
    bool event;
    bool userRaportFlag;
    double m_userGeneratorTime;
    double m_leastTime;


private:
};

#endif