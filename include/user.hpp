
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

typedef enum
{
    BASE_FIRST_POWER_ENUM,
    BASE_SECOND_POWER_ENUM,
    TIME_TO_TRIGGER_FIRST_ACTIVE_ENUM,
    TIME_TO_TRIGGER_SECOND_ACTIVE_ENUM
} base_message_t;

typedef struct 
{
    double power;
    int timeToTrigger;
} base_data_t;


class User {
public:
    User(double t_simulatorTime);
    ~User();

    double getPosition(void);
    connection_t getConnection(void);
    double getRaportTime(void);
    double getBaseData(base_message_t t_messageType);

    void updatePosition(void);
    void updateConnection(connection_t t_connection);
    void updateRaportTime(double t_simulatorTime);

    bool operator==(const User &s) const { return m_position == s.m_position &&
                                                  m_speed == s.m_speed &&
                                                  m_raportTime == s.m_raportTime &&
                                                  m_connection == s.m_connection &&
                                                  &m_firstBase == &s.m_firstBase &&
                                                  &m_secondBase == &s.m_secondBase;}
    bool operator != (const User& s) const { return !operator == (s); }


    void calculatePower(double t_baseFirstPosition, double t_baseSecondPosition);
    bool greaterThanPowerPlus(double t_basePositionX, double t_basePositionY, double t_parameter);
    double calculateSpeed(void);

    int m_TTTfirstToSecond;
    int m_TTTSecondToFirst;
    double m_firstBtsPower;
    double m_secondBtsPower;

private:
    double m_speed;
    double m_position;
    double m_raportTime;

    connection_t m_connection;
    base_data_t m_firstBase;
    base_data_t m_secondBase;
};


#endif