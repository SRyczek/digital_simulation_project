#ifndef USER_HPP
#define USER_HPP

#include <iostream>
#include <cstdlib> 
#include <random>
#include "parameters.hpp"

#define TIME_TO_TRIGGER_PARAMETER 0.1


typedef struct connection {
    bool firstBase;
    bool secondBase;
} connection_t;


class User {
public:
    User(double t_simulatorTime);
    ~User();
    void updatePosition(void);
    double getPosition(void);
    connection_t getConnection(void);
    double calculatePower(double t_basePosition);
    bool greaterThanAlpha(double t_basePositionX, double t_basePositionY);

    bool operator == (const User& s) const { return m_position == s.m_position &&
                                                    m_speed == s.m_speed;}
    bool operator != (const User& s) const { return !operator == (s); }
    void updateRaportTime(double t_simulatorTime);
    double m_raportTime;

    double m_speed;
    int m_TTTfirstToSecond;
    int m_TTTSecondToFirst;

    double m_position;
    connection_t m_connection;    

    double calculateSpeed(void);
};


#endif