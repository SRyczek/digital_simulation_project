
#ifndef USER_HPP
#define USER_HPP

#include <iostream>
#include <cstdlib> 
#include <random>
#include <fstream>

#include "parameters.hpp"

#define BASE_FIRST_NUM 0
#define BASE_SECOND_NUM 1

typedef enum
{
    BASE_FIRST_ENUM,
    BASE_SECOND_ENUM,
    NO_BASE_STATION_CONNECTED
} connection_t;


typedef struct 
{
    double power;
    int timeToTrigger;
} base_data_t;


class User {
public:
    User(double t_simulatorTime, double t_speed);
    ~User();

    double getPosition(void);
    connection_t getConnection(void);
    double getRaportTime(void);
    double getBasePower(int t_baseNum);
    int getTimeToTrigger(int t_baseNum);

    void updatePosition(void);
    void updateConnection(connection_t t_connection);
    void updateRaportTime(double t_simulatorTime);
    void updateTimeToTrigger(int t_baseNum);

    void resetTimeToTrigger(int t_baseNum);

    bool operator==(const User &s) const { return m_position == s.m_position &&
                                                  m_speed == s.m_speed &&
                                                  m_raportTime == s.m_raportTime &&
                                                  m_connection == s.m_connection &&
                                                  &m_firstBase == &s.m_firstBase &&
                                                  &m_secondBase == &s.m_secondBase;}
    bool operator != (const User& s) const { return !operator == (s); }


    void calculatePower(double t_baseFirstPosition, double t_baseSecondPosition);
    bool greaterThanPowerPlus(int t_baseNumConnected, double t_parameter);

private:
    double m_speed;
    double m_position;
    double m_raportTime;

    connection_t m_connection;
    base_data_t m_firstBase;
    base_data_t m_secondBase;
};


#endif