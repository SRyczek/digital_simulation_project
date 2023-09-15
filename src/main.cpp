
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

    // for(int i = 0; i < 1000; i++)
    // {
    //     simulator.generateUserAppearanceTime(LAMBDA);
    //     usleep(500000);
    // }



    while (1)
    {

        if (actualUser == nullptr)
        {
            User *user = new User(simulator.m_simulatorTime);
            simulator.m_simulatorTime = simulator.m_userGeneratorTime;
            network.addUserToQueue(*user);
            simulator.m_userGeneratorTime = simulator.m_simulatorTime + simulator.generateUserAppearanceTime(LAMBDA);
            actualUser = user;
            cout << "actualUser address: " << actualUser << endl;
            cout << "user address: " << &user << endl;
        }
        else
        {
            //actualUser = &network.m_activeUserListInSystem.front();
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
                delete actualUser;
                actualUser = nullptr;
                simulator.event = true;
            }

        }

        if (actualUser != nullptr)
        {
            actualUser->updateRaportTime(simulator.m_simulatorTime);
            simulator.event = true;

        }

        cout << "Simulator time: " << simulator.m_simulatorTime << endl;
        cout << "Kolejka: " << size(network.m_userQueue) << endl;
        cout << "System: " << size(network.m_activeUserListInSystem) << endl;

        usleep(50);
    }

    return 0;
}