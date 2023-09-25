
#include "../include/simulator.hpp"

using namespace std;

mt19937 gen(GAUSSIAN_SEED);
exponential_distribution<> dist(LAMBDA);

Simulator::Simulator()
{
    m_event = true;
    m_changeStationFlag = true;
    m_simulatorTime = 0;
    m_userGeneratorTime = generateUserAppearanceTime();
    memset(m_counter, 0, sizeof(m_counter));
}

Simulator::~Simulator()
{
    
}

double Simulator::generateUserAppearanceTime()
{
    cout << "Generator user time: " << dist(gen) << endl;
    return dist(gen);
}

void Simulator::updateSimulatorTime(double t_updateTime)
{
    m_simulatorTime = t_updateTime;
}
