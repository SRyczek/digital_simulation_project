
#include <iostream>

#include <unistd.h>

#include "../include/base.hpp"
#include "../include/user.hpp"
#include "../include/simulator.hpp"
#include "../include/network.hpp"
#include "../include/logger.hpp"

using namespace std;

int main()
{

    /* variables declaration */
    double baseFirstPosition = 0;
    double baseSecondPosition = 5000;

    std::mt19937 generator(45218965);
    std::uniform_real_distribution<double> distribution(5.0, 50.0);

    Base baseFirst(baseFirstPosition);
    Base baseSecond(baseSecondPosition);
    Simulator simulator;
    Network network;
    User *actualUser = nullptr;
    Logger logger;
    simulator.m_event = false;

    while (1)
    {
        simulator.m_userRaportFlag = false;
        if (actualUser == nullptr)
        {
            User *user = new User(simulator.m_simulatorTime, distribution(generator));
            simulator.m_simulatorTime = simulator.m_userGeneratorTime;
            network.addUserToQueue(*user);
            simulator.m_userGeneratorTime = simulator.m_simulatorTime + simulator.generateUserAppearanceTime();
            actualUser = user;
            actualUser->calculatePower(baseFirst.getPosition(), baseSecond.getPosition());
        }
        else
        {
            for (User &user : network.m_activeUserListInSystem)
            {
                if (user.getRaportTime() < actualUser->getRaportTime())
                {
                    actualUser = &user;
                    actualUser->calculatePower(baseFirst.getPosition(), baseSecond.getPosition());
                }
            }
            if (actualUser->getRaportTime() > simulator.m_userGeneratorTime)
            {
                User *user = new User(simulator.m_simulatorTime, distribution(generator));
                simulator.m_simulatorTime = simulator.m_userGeneratorTime;
                network.addUserToQueue(*user);
                simulator.m_userGeneratorTime = simulator.m_simulatorTime + simulator.generateUserAppearanceTime();
                simulator.m_userRaportFlag = false;
            }
            else if (actualUser->getRaportTime() < simulator.m_userGeneratorTime)
            {
                actualUser->updatePosition();
                simulator.m_simulatorTime += 0.2;
                simulator.m_userRaportFlag = true;
            }
            else if (actualUser->getRaportTime() == simulator.m_userGeneratorTime)
            {
                User *user = new User(simulator.m_simulatorTime, distribution(generator));
                simulator.m_simulatorTime = simulator.m_userGeneratorTime;
                network.addUserToQueue(*user);
                simulator.m_userGeneratorTime = simulator.m_simulatorTime + simulator.generateUserAppearanceTime();
                simulator.m_userRaportFlag = true;
            }
            // cout << "GT: " << simulator.m_userGeneratorTime << endl;
            // cout << "RT: " << actualUser->getRaportTime() << endl;
        }
        simulator.m_event = true;
        simulator.m_changeStationFlag = true;
        simulator.m_resetTimeToTriggerFlag = true;
        while (simulator.m_event == true)
        {
            simulator.m_event = false;
            /* system is not full, add user to system */
            if (size(network.m_activeUserListInSystem) < 80 && size(network.m_userQueue) > 0)
            {
                network.addUserToSystem();
                simulator.m_event = true;
            }
            /* user exceeded distance */
            if (simulator.m_userRaportFlag == true && actualUser->getPosition() > 3000)
            {
                network.removeUserFromSytem(*actualUser);
                simulator.m_counter[EXCEEDED_DISTANCE]++;
                actualUser = &network.m_activeUserListInSystem.front();
                simulator.m_userRaportFlag = false;
                simulator.m_event = true;
            }
            /* change station from first to second */
            if (simulator.m_userRaportFlag == true &&
                actualUser->greaterThanPowerPlus(BASE_FIRST_NUM, ALPHA) &&
                simulator.m_changeStationFlag == true &&
                actualUser->getConnection() == BASE_FIRST_ENUM)
            {
                actualUser->updateTimeToTrigger(BASE_FIRST_NUM);
                actualUser->resetTimeToTrigger(BASE_SECOND_NUM);
                simulator.m_changeStationFlag = false;
                simulator.m_resetTimeToTriggerFlag = false;
                simulator.m_event = true;
            }
            /* change station from second to first */
            if (simulator.m_userRaportFlag == true &&
                actualUser->greaterThanPowerPlus(BASE_SECOND_NUM, ALPHA) &&
                simulator.m_changeStationFlag == true &&
                actualUser->getConnection() == BASE_SECOND_ENUM)
            {
                actualUser->updateTimeToTrigger(BASE_SECOND_NUM);
                actualUser->resetTimeToTrigger(BASE_FIRST_NUM);
                simulator.m_changeStationFlag = false;
                simulator.m_resetTimeToTriggerFlag = false;
                simulator.m_event = true;
            }
            /* reset TTT for both */
            if (simulator.m_userRaportFlag == true &&
                simulator.m_changeStationFlag == true &&
                simulator.m_resetTimeToTriggerFlag == true)
            {
                actualUser->resetTimeToTrigger(BASE_FIRST_NUM);
                actualUser->resetTimeToTrigger(BASE_SECOND_NUM);
                simulator.m_changeStationFlag = false;
                simulator.m_event = true;
            }

            if (simulator.m_userRaportFlag == true &&
                actualUser->getTimeToTrigger(BASE_FIRST_NUM) >= TIME_TO_TRIGGER_CONVERTED &&
                actualUser->getConnection() == BASE_FIRST_ENUM)
            {
                ofstream file("../logger/logger.txt", ios::app);
                if (!file.is_open())
                {
                    cerr << "Cannot open file" << endl;
                    exit(-1);
                }
                //file << actualUser->getPosition() << endl;
                actualUser->updateConnection(BASE_SECOND_ENUM);
                simulator.m_counter[CHANGE_STATION_FTS]++;
                actualUser->resetTimeToTrigger(BASE_FIRST_NUM);
                actualUser->resetTimeToTrigger(BASE_SECOND_NUM);
                simulator.m_event = true;
            }
            if (simulator.m_userRaportFlag == true &&
                actualUser->getTimeToTrigger(BASE_SECOND_NUM) >= TIME_TO_TRIGGER_CONVERTED &&
                actualUser->getConnection() == BASE_SECOND_ENUM)
            {

                ofstream file("../logger/logger.txt", ios::app);
                if (!file.is_open())
                {
                    cerr << "Cannot open file" << endl;
                    exit(-1);
                }
                //file << actualUser->getPosition() << endl;

                actualUser->updateConnection(BASE_FIRST_ENUM);
                simulator.m_counter[CHANGE_STATION_STF]++;
                actualUser->resetTimeToTrigger(BASE_FIRST_NUM);
                actualUser->resetTimeToTrigger(BASE_SECOND_NUM);
                simulator.m_event = true;
            }
            if (simulator.m_userRaportFlag == true &&
            ((actualUser->greaterThanPowerPlus(BASE_FIRST_NUM, DELTA) && actualUser->getConnection() == BASE_SECOND_ENUM) ||
            (actualUser->greaterThanPowerPlus(BASE_SECOND_NUM, DELTA) && actualUser->getConnection() == BASE_FIRST_ENUM)))
            {
                network.removeUserFromSytem(*actualUser);
                actualUser = &network.m_activeUserListInSystem.front();
                simulator.m_counter[CONNECTION_BREAKUP]++;
                simulator.m_userRaportFlag = false;
                simulator.m_event = true;
            }

            if (size(network.m_userQueue) == 0 &&
                size(network.m_activeUserListInSystem) == 0 &&
                actualUser != nullptr)
            {

                actualUser = nullptr;
                simulator.m_userRaportFlag = false;
                simulator.m_event = true;
            }
        }

        if (simulator.m_userRaportFlag == true)
        {
            actualUser->updateRaportTime(simulator.m_simulatorTime);
        }

        cout << "Simulator time: " << simulator.m_simulatorTime << endl;
        cout << "Kolejka: " << size(network.m_userQueue) << endl;
        cout << "System: " << size(network.m_activeUserListInSystem) << endl;
        cout << "Position: " << actualUser->getPosition() << endl;
        cout << "TTT: " << actualUser->getTimeToTrigger(BASE_FIRST_NUM) << endl;

        if (simulator.m_simulatorTime > logger.getLoggerTimer() && LOGGER_FLAG == 1)
        {
            logger.addToFile(simulator.m_simulatorTime, USER_IN_SYSTEM_ENUM, size(network.m_activeUserListInSystem));
            logger.addToFile(simulator.m_simulatorTime, USER_IN_QUEUE_ENUM, size(network.m_userQueue));
            logger.addToFile(simulator.m_simulatorTime, CHANGE_STATION_FTS_ENUM, simulator.m_counter[CHANGE_STATION_FTS]);
            logger.addToFile(simulator.m_simulatorTime, CHANGE_STATION_STF_ENUM, simulator.m_counter[CHANGE_STATION_STF]);
            logger.addToFile(simulator.m_simulatorTime, EXCEEDED_DISTANCE_ENUM, simulator.m_counter[EXCEEDED_DISTANCE]);
            logger.addToFile(simulator.m_simulatorTime, CONNECTION_BREAKUP_ENUM, simulator.m_counter[CONNECTION_BREAKUP]);
            logger.addToFile(0, NEWLINE_ENUM, 0);
            logger.updateLoggerTimer();
        }

    usleep(10);
    }

    return 0;
}