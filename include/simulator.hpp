
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

    bool m_event;
    bool m_userRaportFlag;
    double m_userGeneratorTime;
    double m_leastTime;
    int m_eventLoopIterator;
    double m_simulatorTime;

private:

};

#endif