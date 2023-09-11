#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP

#include <random>

#define LAMBDA 0.5

class Simulator {
public:
Simulator();
~Simulator();
double generateUserAppearanceTime(double t_lambda);
double simulatorTime;
bool event;
private:

};

#endif