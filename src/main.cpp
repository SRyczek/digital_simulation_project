
#include <iostream>
#include <unistd.h>
#include "../include/base.hpp"
#include "../include/user.hpp"
#include "../include/simulator.hpp"
#include "../include/network.hpp"

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
    simulator.event = false;
    int counter = 0;

    // for(int i = 0; i < 1000; i++)
    // {
    //     simulator.generateUserAppearanceTime(LAMBDA);
    //     usleep(500000);
    // }

    while (1)
    {
        simulator.userRaportFlag = false;
        if (actualUser == nullptr)
        {
            User *user = new User(simulator.m_simulatorTime);
            simulator.m_simulatorTime = simulator.m_userGeneratorTime;
            network.addUserToQueue(*user);
            simulator.m_userGeneratorTime = simulator.m_simulatorTime + simulator.generateUserAppearanceTime(LAMBDA);
            actualUser = user;
        }
        else
        {
            for (User &user : network.m_activeUserListInSystem)
            {
                if (user.m_raportTime < actualUser->m_raportTime)
                {
                    actualUser = &user;
                }
            }
            if (actualUser->m_raportTime > simulator.m_userGeneratorTime)
            {
                User *user = new User(simulator.m_simulatorTime);
                simulator.m_simulatorTime = simulator.m_userGeneratorTime;
                network.addUserToQueue(*user);
                simulator.m_userGeneratorTime = simulator.m_simulatorTime + simulator.generateUserAppearanceTime(LAMBDA);
                simulator.userRaportFlag = false;
            }
            else if (actualUser->m_raportTime < simulator.m_userGeneratorTime)
            {
                simulator.userRaportFlag = true;
                actualUser->updatePosition();
                simulator.m_simulatorTime += 0.2;
            }
            else if (actualUser->m_raportTime == simulator.m_userGeneratorTime)
            {
                User *user = new User(simulator.m_simulatorTime);
                simulator.m_simulatorTime = simulator.m_userGeneratorTime;
                network.addUserToQueue(*user);
                simulator.m_userGeneratorTime = simulator.m_simulatorTime + simulator.generateUserAppearanceTime(LAMBDA);
                simulator.userRaportFlag = true;
            }
            cout << "GT: " << simulator.m_userGeneratorTime << endl;
            cout << "RT: " << actualUser->m_raportTime << endl;
        }
        simulator.eventLoopIterator = 0;
        simulator.event = true;
        while (simulator.event == true)
        {
            simulator.event = false;
            if (size(network.m_activeUserListInSystem) < 80 && size(network.m_userQueue) > 0)
            {
                network.addUserToSystem();
                simulator.event = true;
            }
            if (simulator.userRaportFlag == true && actualUser->getPosition() > 3000)
            {
                network.removeUserFromSytem(*actualUser);
                actualUser = &network.m_activeUserListInSystem.front();
                simulator.userRaportFlag = false;
                simulator.event = true;
            }
            if (actualUser->getConnection() == BASE_FIRST_ENUM &&
                simulator.userRaportFlag == true &&
                actualUser->greaterThanAlpha(baseFirst.getPosition(), baseSecond.getPosition()) &&
                simulator.eventLoopIterator == 0)
            {
                actualUser->m_TTTfirstToSecond++;
                actualUser->m_TTTSecondToFirst = 0;
                simulator.event = true;
            }
            else if (actualUser->getConnection() == BASE_SECOND_ENUM &&
                     simulator.userRaportFlag == true &&
                     actualUser->greaterThanAlpha(baseSecond.getPosition(), baseFirst.getPosition()) &&
                     simulator.eventLoopIterator == 0)
            {
                actualUser->m_TTTSecondToFirst++;
                actualUser->m_TTTfirstToSecond = 0;
                simulator.event = true;
            }
            else if (actualUser->getConnection() == NO_BASE_STATION_CONNECTED &&
                     simulator.userRaportFlag == true &&
                     simulator.eventLoopIterator == 0)
            {
                actualUser->m_TTTSecondToFirst = 0;
                actualUser->m_TTTfirstToSecond = 0;
            }
            else 
            {
                cout << "Change connection error" << endl;
            }
            if (simulator.userRaportFlag == true &&
                actualUser->m_TTTfirstToSecond >= 5 &&
                actualUser->getConnection() == BASE_FIRST_ENUM)
            {
                cout << "Change station" << endl;
                /* code to change station */
                simulator.event = true;
                actualUser->updateConnection(BASE_SECOND_ENUM);
                counter++;
            }
            if (simulator.userRaportFlag == true &&
                actualUser->m_TTTSecondToFirst >= 5 &&
                actualUser->getConnection() == BASE_SECOND_ENUM)
            {
                cout << "Change station" << endl;
                /* code to change station */
                simulator.event = true;
                actualUser->updateConnection(BASE_FIRST_ENUM);
                counter++;
            }
            if(simulator.userRaportFlag == true &&
              actualUser->)
            {
                
            }

            simulator.eventLoopIterator++;
        }

        if (simulator.userRaportFlag == true)
        {
            actualUser->updateRaportTime(simulator.m_simulatorTime);
        }

        cout << "Simulator time: " << simulator.m_simulatorTime << endl;
        cout << "Kolejka: " << size(network.m_userQueue) << endl;
        cout << "System: " << size(network.m_activeUserListInSystem) << endl;
        cout << "Change number: " << counter << endl;

        usleep(500);
    }

    return 0;
}