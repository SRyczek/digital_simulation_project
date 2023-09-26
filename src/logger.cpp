
#include "../include/logger.hpp"

using namespace std;

ofstream file("../logger/logger.txt", ios::app);

Logger::Logger()
{
    if (!file.is_open())
    {
        cerr << "Cannot open file" << endl;
        exit(-1);
    }
    else if (LOGGER_FLAG == 1)
    {
        //file << endl << endl;
    }

}

Logger::~Logger()
{

}

double Logger::getLoggerTimer()
{
    return m_loggerTimer;
}

void Logger::updateLoggerTimer()
{
    m_loggerTimer += LOGGER_OFFSET;
}

void Logger::addToFile(double t_simulatorTime, string t_message, int t_data)
{
    if (LOGGER_FLAG == 1)
    {
        if (!file.is_open())
        {
            cerr << "Cannot open file" << endl;
            exit(-1);
        }
        // file << t_simulatorTime << " : " << t_message << " : " << t_data << endl;
        //exit(0);
        file << t_data << endl;
        // file << t_message;
    }

}

void Logger::addToFile(double t_simulatorTime, string t_message, int t_data, int t_data2)
{
    if (LOGGER_FLAG == 1)
    {
        if (!file.is_open())
        {
            cerr << "Cannot open file" << endl;
            exit(-1);
        }
        // file << t_simulatorTime << " : " << t_message << " : " << t_data << endl;
        file << t_data << "\t" << t_data2 << endl;
    }

}

void Logger::addToFile(double t_simulatorTime, string t_message, int t_data, int t_data2, int t_data3)
{
    if (LOGGER_FLAG == 1) 
    {
        if (!file.is_open())
        {
            cerr << "Cannot open file" << endl;
            exit(-1);
        }
        // file << t_simulatorTime << " : " << t_message << " : " << t_data << endl;
        file << t_data << "\t" << t_data2 << "\t" << t_data3 << endl;
    }
}

void Logger::addToFile(double t_simulatorTime, string t_message, int t_data, int t_data2, int t_data3, int t_data4)
{
    if (LOGGER_FLAG == 1)
    {
        if (!file.is_open())
        {
            cerr << "Cannot open file" << endl;
            exit(-1);
        }
        // file << t_simulatorTime << " : " << t_message << " : " << t_data << endl;
        file << t_data << "\t" << t_data2 << "\t" << t_data3 << "\t" << t_data4 << endl;
    }
}

void Logger::addToFile(double t_simulatorTime, string t_message, int t_data, int t_data2, int t_data3, int t_data4, int t_data5)
{
    if (LOGGER_FLAG == 1)
    {
        if (!file.is_open())
        {
            cerr << "Cannot open file" << endl;
            exit(-1);
        }
        // file << t_simulatorTime << " : " << t_message << " : " << t_data << endl;
        file << t_data << "\t" << t_data2 << "\t" << t_data3 << "\t" << t_data4 << "\t" << t_data5 << endl;
    }
}