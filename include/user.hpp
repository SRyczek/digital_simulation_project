
#ifndef USER_HPP
#define USER_HPP

#include <iostream>
#include <cstdlib> 
#include <random>
#include "parameters.hpp"

typedef enum
{
    BASE_FIRST_ENUM,
    BASE_SECOND_ENUM,
    NO_BASE_STATION_CONNECTED
} connection_t;

class User {
public:
    User(double t_simulatorTime);
    ~User();
    void updatePosition(void);
    double getPosition(void);
    connection_t getConnection(void);
    void updateConnection(connection_t t_connection);
    void calculatePower(double t_baseFirstPosition, double t_baseSecondPosition);
    bool greaterThanPowerPlus(double t_basePositionX, double t_basePositionY, double t_parameter);

    bool operator == (const User& s) const { return m_position == s.m_position &&
                                                    m_speed == s.m_speed;}
    bool operator != (const User& s) const { return !operator == (s); }
    void updateRaportTime(double t_simulatorTime);
    double calculateSpeed(void);

    double m_raportTime;
    int m_TTTfirstToSecond;
    int m_TTTSecondToFirst;
    connection_t m_connection;
    double m_firstBtsPower;
    double m_secondBtsPower;

private:
    double m_speed;
    double m_position;

};


#endif