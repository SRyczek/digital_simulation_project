
#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>
#include <fstream>

#include "parameters.hpp"

typedef enum
{
    START_MESSAGE_ENUM,
    USER_IN_SYSTEM_ENUM,
    USER_IN_QUEUE_ENUM,
    NEWLINE_ENUM,
    CHANGE_STATION_FTS_ENUM,
    CHANGE_STATION_STF_ENUM,
    EXCEEDED_DISTANCE_ENUM,
    CONNECTION_BREAKUP_ENUM

} message_t;

class Logger
{
public:
    Logger();
    ~Logger();
    void addToFile(double t_simulatorTime, message_t t_message, int t_data);
    double getLoggerTimer();
    void updateLoggerTimer();

private:
    double m_loggerTimer;
};

#endif