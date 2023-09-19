
#include "../include/user.hpp"

using namespace std;

User::User(double t_simulatorTime)
{
    cout << "Create User" << endl;
    m_speed = calculateSpeed();
    m_position = 2000;
    m_raportTime = t_simulatorTime + 0.02;
    m_connection = BASE_FIRST_ENUM;
}

User::~User()
{
    cout << "Deleted user" << endl;
}

double User::calculateSpeed(void)
{
    int range = 50 - 5 + 1;
    int num = rand() % range + 5; /* random variable from the range of 5 - 50 */
    return num * 0.02;            /* update location once to 20 ms */
}

void User::updatePosition(void)
{
    m_position += m_speed;
    cout << "Actual position: " << m_position << endl;
}

void User::updateRaportTime(double t_simulatorTime)
{
    m_raportTime = t_simulatorTime + 0.02;
}

double User::calculatePower(double t_basePosition)
{
    double distanceToBase = abs(m_position - t_basePosition);
    std::mt19937 gen(123);
    std::normal_distribution<double> dist(0, 4);
    return (4.61 - 22 * log10(distanceToBase) + dist(gen));
}

double User::getPosition(void)
{
    return m_position;
}

connection_t User::getConnection(void)
{
    return m_connection;
}

void User::updateConnection(connection_t t_connection)
{
    m_connection = t_connection;
}

bool User::greaterThanPowerPlus(double t_basePositionX, double t_basePositionY, double t_parameter)
{
    double powerX = calculatePower(t_basePositionX);
    double powerY = calculatePower(t_basePositionY);

    if (powerX > powerY + t_parameter)
    {
        return true;
    }
    else 
    {
        return false;
    }

}
