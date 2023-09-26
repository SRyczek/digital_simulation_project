
#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "parameters.hpp"

class Logger
{
public:
    Logger();
    ~Logger();
    void addToFile(double t_simulatorTime, std::string t_message, int t_data);
    void addToFile(double t_simulatorTime, std::string t_message, int t_data, int t_data2);
    void addToFile(double t_simulatorTime, std::string t_message, int t_data, int t_data2, int t_data3);
    void addToFile(double t_simulatorTime, std::string t_message, int t_data, int t_data2, int t_data3, int t_data4);
    void addToFile(double t_simulatorTime, std::string t_message, int t_data, int t_data2, int t_data3, int t_data4, int t_data5);
    double getLoggerTimer();
    void updateLoggerTimer();

private:
    double m_loggerTimer;
};

#endif