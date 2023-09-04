#ifndef USER_HPP
#define USER_HPP

#include <iostream>
#include <cstdlib> 
#include <random>

#define ALPHA_PARAMETER 3


typedef struct connection {
    bool firstBase;
    bool secondBase;
} connection_t;


class User {
public:
    User();
    ~User();
    void updatePosition(void);
    double getPosition();
    double calculatePower(double t_basePosition);
    void changeStation(double t_baseFisrtPosition, double t_baseSecondPosition);
private:
    double m_position;
    double m_speed;

    connection_t m_connection;    

    double calculateSpeed(void);
};


#endif