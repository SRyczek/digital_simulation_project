
#include "../include/logger.hpp"

using namespace std;

Logger::Logger()
{
    addToFile(0, START_MESSAGE_ENUM, 0);

}

Logger::~Logger()
{
}

void Logger::addToFile(double t_simulatorTime, message_t t_message, int t_data)
{

    ofstream file("../logger/logger.txt", ios::app);
    if (!file.is_open())
    {
        cerr << "Cannot open file" << endl;
        exit(-1);
    }
    switch (t_message)
    {
    case START_MESSAGE_ENUM:
    file << endl << endl;
    file << t_simulatorTime << ": Simulator start " << t_data << endl;
    break;
    case USER_IN_SYSTEM_ENUM:
    file << t_simulatorTime << ": User in system: " << t_data << endl;
    break;


    default:
        cerr << "ERROR MESSAGE" << endl;
        exit(-1);

        break;
    }


}