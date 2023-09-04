#ifndef USER_HPP
#define USER_HPP

#include <iostream>
#include <cstdlib> 
#include <random>

#define ALPHA_PARAMETER 3
#define TIME_TO_TRIGGER_PARAMETER 0.1


typedef struct connection {
    bool firstBase;
    bool secondBase;
} connection_t;


class User {
public:
    User();
    ~User();
    void updatePosition(void);
    double getPosition(void);
    connection_t getConnection(void);
    double calculatePower(double t_basePosition);
    void changeStation(double t_baseFisrtPosition, double t_baseSecondPosition, double t_time);
private:
    double m_position;
    double m_speed;
    double m_timeToTrigger;

    connection_t m_connection;    

    double calculateSpeed(void);
};


#endif