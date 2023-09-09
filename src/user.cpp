
#include "../include/user.hpp"

using namespace std;

User::User() {
    cout << "Create User" << endl;
    m_speed = calculateSpeed();
    m_position = 2000;
    m_timeToTrigger = 0;
    m_connection.firstBase = true;
    m_connection.secondBase = false;
}

User::~User() {
    cout << "Deleted user" << endl;
}

double User::calculateSpeed(void) {
    int range = 50 - 5 + 1;
    int num = rand() % range + 5;   /* random variable from the range of 5 - 50 */
    return num * 0.02;              /* update location once to 20 ms */
}

void User::updatePosition(void) {
    m_position += m_speed;
}

double User::calculatePower(double t_basePosition) {
    double distanceToBase = abs(m_position - t_basePosition);
    std::mt19937 gen(123);
    std::normal_distribution<double> dist(0, 4);
    return (4.61 - 22 * log10(distanceToBase) + dist(gen));
}

double User::getPosition(void) {
    return m_position;
}

connection_t User::getConnection(void) {
    return m_connection;
}

void User::changeStation(double t_baseFisrtPosition, double t_baseSecondPosition, double t_time) {
    double powerFirst = calculatePower(t_baseFisrtPosition);
    double powerSecond = calculatePower(t_baseSecondPosition);
    if (m_connection.firstBase == true && m_connection.secondBase == false) {
        if (powerSecond > (powerFirst + ALPHA_PARAMETER)) {

            m_timeToTrigger += t_time;
            if (m_timeToTrigger > TIME_TO_TRIGGER_PARAMETER) {
                m_connection.firstBase = false;
                m_connection.secondBase = true;
                m_timeToTrigger = 0;
                cout << "Change station to second" << endl;
            }
        } else {
            m_timeToTrigger = 0;
        }
    } else if (m_connection.firstBase == false && m_connection.secondBase == true) {

        if (powerFirst > (powerSecond + ALPHA_PARAMETER))
        {

            m_timeToTrigger += t_time;
            if (m_timeToTrigger > TIME_TO_TRIGGER_PARAMETER) {
                m_connection.firstBase = true;
                m_connection.secondBase = false;
                m_timeToTrigger = 0;
                cout << "Change station to first" << endl;
            }
        } else {
            m_timeToTrigger = 0;
        }
    } else {
        cout << "changeStation ERROR" << endl;
        exit(1);
    }
}
