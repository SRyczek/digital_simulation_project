#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP

#include <random>
#include "parameters.hpp"

class Simulator {
public:
    Simulator();
    ~Simulator();
    double generateUserAppearanceTime(double t_lambda);
    void updateSimulatorTime(double t_updateTime);
    double m_simulatorTime;
    bool event;
    double m_userGeneratorTime;
    double m_leastTime;

private:
};

#endif