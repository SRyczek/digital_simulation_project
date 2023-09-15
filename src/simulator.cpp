
#include "../include/simulator.hpp"

using namespace std;

Simulator::Simulator()
{
    m_simulatorTime = 0;
    m_userGeneratorTime = generateUserAppearanceTime(LAMBDA);
}

Simulator::~Simulator()
{
}

double Simulator::generateUserAppearanceTime(double t_lambda)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::exponential_distribution<> dist(t_lambda);
    cout << "Generator user time: " << dist(gen) << endl;
    return dist(gen);
}

void Simulator::updateSimulatorTime(double t_updateTime)
{
    m_simulatorTime = t_updateTime;
}