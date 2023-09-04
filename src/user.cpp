
#include "../include/user.hpp"

using namespace std;

User::User() {
    cout << "Create User" << endl;
    m_speed = calculateSpeed();
    m_position = 2000;

    m_connection.firstBase = true;
    m_connection.secondBase = false;
}

User::~User() {
    cout << "Deleted user" << endl;
}

double User::calculateSpeed(void) {
    int range = 50 - 5 + 1;
    int num = rand() % range + 5;
    return num * 0.02;
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

void User::changeStation(double t_baseFisrtPosition, double t_baseSecondPosition) {
    double powerFirst = calculatePower(t_baseFisrtPosition);
    double powerSecond = calculatePower(t_baseSecondPosition);
    if (powerSecond > (powerFirst + ALPHA_PARAMETER)) {
       
    }
}

