
#include "../include/user.hpp"

using namespace std;

std::mt19937 generator(EXPONENTIAL_SEED);
std::normal_distribution<double> normDist(0, 4);

User::User(double t_simulatorTime, double t_speed)
{
    cout << "Create User" << endl;
    m_speed = t_speed * 0.02;
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


void User::updatePosition(void)
{
    m_position += m_speed;
    //cout << "Actual position: " << m_position << endl;
}

void User::updateRaportTime(double t_simulatorTime)
{
    m_raportTime = t_simulatorTime + 0.02;
}

int User::getTimeToTrigger(int t_baseNum)
{
    if (t_baseNum == BASE_FIRST_NUM)
    {
        return m_firstBase.timeToTrigger;
    }
    else if (t_baseNum == BASE_SECOND_NUM)
    {
        return m_secondBase.timeToTrigger;
    }
    else
    {
         cerr << "getTimeToTrigger ERROR" << endl;
         exit(-1);
    }
}

void User::updateTimeToTrigger(int t_baseNum)
{
    if (t_baseNum == BASE_FIRST_NUM)
    {
        m_firstBase.timeToTrigger++;
    }
    else if (t_baseNum == BASE_SECOND_NUM)
    {
        m_secondBase.timeToTrigger++;
    }
    else
    {
        cerr << "updateTimeToTrigger ERROR" << endl;
        exit(-1);
    }
}

void User::resetTimeToTrigger(int t_baseNum)
{
    if (t_baseNum == BASE_FIRST_NUM)
    {
        m_firstBase.timeToTrigger = 0;
    }
    else if (t_baseNum == BASE_SECOND_NUM)
    {
        m_secondBase.timeToTrigger = 0;
    }
    else
    {
        cerr << "resetTimeToTrigger ERROR" << endl;
        exit(-1);
    }
}

void User::calculatePower(double t_baseFirstPosition, double t_baseSecondPosition)
{
    m_firstBase.power = (4.61 - 22 * log10(abs(m_position - t_baseFirstPosition)) + normDist(generator));
    m_secondBase.power = (4.61 - 22 * log10(abs(m_position - t_baseSecondPosition)) + normDist(generator));

    //cout << "Power first: " << m_firstBase.power << endl;
    //cout << "Power second: " << m_secondBase.power << endl;
}

double User::getPosition(void)
{
    return m_position;
}

connection_t User::getConnection(void)
{
    return m_connection;
}

double User::getBasePower(int t_baseNum)
{
    if (t_baseNum == BASE_FIRST_NUM)
    {
        return m_firstBase.power;
    }
    else if (t_baseNum == BASE_SECOND_NUM)
    {
        return m_secondBase.power;
    }
    else
    {
        cerr << "getBasePower ERROR" << endl;
        exit(-1);
    }
}

void User::updateConnection(connection_t t_connection)
{
    m_connection = t_connection;
}

bool User::greaterThanPowerPlus(int t_baseNumConnected, double t_parameter)
{

    if (t_baseNumConnected == BASE_SECOND_NUM)
    {
        if (m_firstBase.power > m_secondBase.power + t_parameter)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (t_baseNumConnected == BASE_FIRST_NUM)
    {
        if (m_secondBase.power > m_firstBase.power + t_parameter)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else 
    {
        cerr << "Greater than power plus ERROR" << endl;
        exit(-1);
    }
}
