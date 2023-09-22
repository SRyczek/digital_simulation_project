
#include "../include/user.hpp"

using namespace std;

std::mt19937 generator(45218965);
std::normal_distribution<double> normDist(0, 4);

User::User(double t_simulatorTime)
{
    cout << "Create User" << endl;
    m_speed = calculateSpeed();
    m_position = 2000;
    updateRaportTime(t_simulatorTime);
    m_connection = BASE_FIRST_ENUM;
}

User::~User()
{
    cout << "Deleted user" << endl;
}

double User::getRaportTime(void)
{
    return m_raportTime;
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

void User::calculatePower(double t_baseFirstPosition, double t_baseSecondPosition)
{
    m_firstBtsPower =  (4.61 - 22 * log(abs(m_position - t_baseFirstPosition)) + normDist(generator));
    m_secondBtsPower = (4.61 - 22 * log(abs(m_position - t_baseSecondPosition)) + normDist(generator));
}

double User::getPosition(void)
{
    return m_position;
}

connection_t User::getConnection(void)
{
    return m_connection;
}

double User::getBaseData(base_message_t t_messageType)
{
    if (t_messageType == BASE_FIRST_POWER_ENUM)
    {
        return m_firstBase.power;
    }
    else if (t_messageType == BASE_SECOND_POWER_ENUM)
    {
        return m_secondBase.power;
    }
    else if (t_messageType == TIME_TO_TRIGGER_FIRST_ACTIVE_ENUM)
    {
        return m_firstBase.timeToTrigger;
    }
    else if (t_messageType == TIME_TO_TRIGGER_SECOND_ACTIVE_ENUM)
    {
        return m_secondBase.timeToTrigger;
    }
    else 
    {
        cerr << "getBaseData ERROR" << endl;
        exit(-1);
    }
}


    void User::updateConnection(connection_t t_connection)
{
    m_connection = t_connection;
}

bool User::greaterThanPowerPlus(double t_basePositionX, double t_basePositionY, double t_parameter)
{
    cout << "Power1: " << m_firstBtsPower << " Power2: " << m_secondBtsPower << endl;
    if (m_firstBtsPower > m_secondBtsPower + t_parameter)
    {
        return true;
    }
    else 
    {
        return false;
    }

}
