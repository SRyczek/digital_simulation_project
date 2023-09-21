
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
            User *user = new User(simulator.m_simulatorTime);
            simulator.m_simulatorTime = simulator.m_userGeneratorTime;
            network.addUserToQueue(*user);
            simulator.m_userGeneratorTime = simulator.m_simulatorTime + simulator.generateUserAppearanceTime();
            actualUser = user;
        }
        else
        {
            for (User &user : network.m_activeUserListInSystem)
            {
                if (user.m_raportTime < actualUser->m_raportTime)
                {
                    actualUser = &user;
                    actualUser->calculatePower(baseFirst.getPosition(), baseSecond.getPosition());
                }
            }
            if (actualUser->m_raportTime > simulator.m_userGeneratorTime)
            {
                User *user = new User(simulator.m_simulatorTime);
                simulator.m_simulatorTime = simulator.m_userGeneratorTime;
                network.addUserToQueue(*user);
                simulator.m_userGeneratorTime = simulator.m_simulatorTime + simulator.generateUserAppearanceTime();
                simulator.m_userRaportFlag = false;
            }
            else if (actualUser->m_raportTime < simulator.m_userGeneratorTime)
            {
                actualUser->updatePosition();
                simulator.m_simulatorTime += 0.2;
                simulator.m_userRaportFlag = true;
            }
            else if (actualUser->m_raportTime == simulator.m_userGeneratorTime)
            {
                User *user = new User(simulator.m_simulatorTime);
                simulator.m_simulatorTime = simulator.m_userGeneratorTime;
                network.addUserToQueue(*user);
                simulator.m_userGeneratorTime = simulator.m_simulatorTime + simulator.generateUserAppearanceTime();
                simulator.m_userRaportFlag = true;
            }
            cout << "GT: " << simulator.m_userGeneratorTime << endl;
            cout << "RT: " << actualUser->m_raportTime << endl;
        }
        simulator.m_event = true;
        simulator.m_changeStationFlag = true;
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
            if (actualUser->getConnection() == BASE_FIRST_ENUM &&
                simulator.m_userRaportFlag == true &&
                actualUser->greaterThanPowerPlus(baseFirst.getPosition(), baseSecond.getPosition(), ALPHA) &&
                simulator.m_changeStationFlag == true)
            {
                actualUser->m_TTTfirstToSecond++;
                actualUser->m_TTTSecondToFirst = 0;
                simulator.m_event = true;
                simulator.m_changeStationFlag = false;
            }
            /* change station from second to first */
            else if (actualUser->getConnection() == BASE_SECOND_ENUM &&
                     simulator.m_userRaportFlag == true &&
                     actualUser->greaterThanPowerPlus(baseSecond.getPosition(), baseFirst.getPosition(), ALPHA) &&
                     simulator.m_changeStationFlag == true)
            {
                actualUser->m_TTTSecondToFirst++;
                actualUser->m_TTTfirstToSecond = 0;
                simulator.m_changeStationFlag = false;
                simulator.m_event = true;
            }
            else if (actualUser->getConnection() == NO_BASE_STATION_CONNECTED &&
                     simulator.m_userRaportFlag == true &&
                     simulator.m_changeStationFlag == true)
            {
                actualUser->m_TTTSecondToFirst = 0;
                actualUser->m_TTTfirstToSecond = 0;
                simulator.m_changeStationFlag = false;
                simulator.m_event = true;
            }
            else if (simulator.m_userRaportFlag == true &&
                     simulator.m_changeStationFlag == true)
            {
                actualUser->m_TTTSecondToFirst = 0;
                actualUser->m_TTTfirstToSecond = 0;
                simulator.m_event = true;
                simulator.m_changeStationFlag = false;
            }

            if (simulator.m_userRaportFlag == true &&
                actualUser->m_TTTfirstToSecond >= 5 &&
                actualUser->getConnection() == BASE_FIRST_ENUM)
            {
                actualUser->updateConnection(BASE_SECOND_ENUM);
                simulator.m_counter[CHANGE_STATION_FTS]++;
                actualUser->m_TTTfirstToSecond = 0;
                simulator.m_event = true;
            }
            if (simulator.m_userRaportFlag == true &&
                actualUser->m_TTTSecondToFirst >= 5 &&
                actualUser->getConnection() == BASE_SECOND_ENUM)
            {
                actualUser->updateConnection(BASE_FIRST_ENUM);
                simulator.m_counter[CHANGE_STATION_STF]++;
                actualUser->m_TTTSecondToFirst = 0;
                simulator.m_event = true;
            }
            if (simulator.m_userRaportFlag == true &&
                (actualUser->greaterThanPowerPlus(baseFirst.getPosition(), baseSecond.getPosition(), DELTA) ||
                 actualUser->greaterThanPowerPlus(baseSecond.getPosition(), baseFirst.getPosition(), DELTA)))
            {
                cout << "Test" << endl;
                network.removeUserFromSytem(*actualUser);
                actualUser = &network.m_activeUserListInSystem.front();
                simulator.m_counter[CONNECTION_BREAKUP]++;
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

        if (simulator.m_simulatorTime > logger.m_loggerTimer)
        {
            logger.addToFile(simulator.m_simulatorTime, USER_IN_SYSTEM_ENUM, size(network.m_activeUserListInSystem));
            logger.addToFile(simulator.m_simulatorTime, USER_IN_QUEUE_ENUM, size(network.m_userQueue));
            logger.addToFile(simulator.m_simulatorTime, CHANGE_STATION_FTS_ENUM, simulator.m_counter[CHANGE_STATION_FTS]);
            logger.addToFile(simulator.m_simulatorTime, CHANGE_STATION_STF_ENUM, simulator.m_counter[CHANGE_STATION_STF]);
            logger.addToFile(simulator.m_simulatorTime, EXCEEDED_DISTANCE_ENUM, simulator.m_counter[EXCEEDED_DISTANCE]);
            logger.addToFile(simulator.m_simulatorTime, CONNECTION_BREAKUP_ENUM, simulator.m_counter[CONNECTION_BREAKUP]);
            logger.addToFile(0, NEWLINE_ENUM, 0);
            logger.m_loggerTimer += LOGGER_OFFSET;
        }

        usleep(1000);
    }

    return 0;
}
