
#include "../include/logger.hpp"

using namespace std;

Logger::Logger()
{
    addToFile(0, START_MESSAGE_ENUM, 0);
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

void Logger::addToFile(double t_simulatorTime, message_t t_message, int t_data)
{

    ofstream file("../logger/logger.txt", ios::app);
    if (!file.is_open())
    {
        cerr << "Cannot open file" << endl;
        //exit(-1);
    }
    switch (t_message)
    {
    case START_MESSAGE_ENUM:
        file << endl
             << endl;
        file << t_simulatorTime << ": Simulator start " << t_data << endl;
        break;
    case USER_IN_SYSTEM_ENUM:
        file << t_simulatorTime << ": User in system: " << t_data << endl;
        break;
    case USER_IN_QUEUE_ENUM:
        file << t_simulatorTime << ": User in queue: " << t_data << endl;
        break;
    case CHANGE_STATION_FTS_ENUM:
        file << t_simulatorTime << ": Change station from first to second: " << t_data << endl;
        break;
    case CHANGE_STATION_STF_ENUM:
        file << t_simulatorTime << ": Change station from second to first: " << t_data << endl;
        break;
    case EXCEEDED_DISTANCE_ENUM:
        file << t_simulatorTime << ": Users exceeded distance: " << t_data << endl;
        break;
    case CONNECTION_BREAKUP_ENUM:
        file << t_simulatorTime << ": User connection breakup: " << t_data << endl;

    case NEWLINE_ENUM:
        file << endl;
        break;
    default:
        cerr << "ERROR MESSAGE" << endl;
        exit(-1);

        break;
    }
}