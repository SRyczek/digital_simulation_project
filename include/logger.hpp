
#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>
#include <fstream>

typedef enum
{
    START_MESSAGE_ENUM,
    USER_IN_SYSTEM_ENUM

} message_t;

class Logger
{
public:
    Logger();
    ~Logger();
    void addToFile(double t_simulatorTime, message_t t_message, int t_data);
    double m_loggerTimer;

private:

};

#endif