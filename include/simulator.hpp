
#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP

#include <random>
#include <iostream>
#include <cstring>
#include <cmath>

#include "parameters.hpp"

#define CHANGE_STATION_FTS 0
#define CHANGE_STATION_STF 1
#define EXCEEDED_DISTANCE 2
#define CONNECTION_BREAKUP 3

class Simulator {
public:
    Simulator();
    ~Simulator();
    double generateUserAppearanceTime();
    void updateSimulatorTime(double t_updateTime);

    bool m_event;
    bool m_userRaportFlag;
    double m_userGeneratorTime;
    double m_leastTime;
    bool m_changeStationFlag;
    double m_simulatorTime;
    int m_counter[4];
private:
};

#endif