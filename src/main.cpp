
#include <iostream>
#include <unistd.h>
#include "../include/base.hpp"
#include "../include/user.hpp"
#include "../include/simulator.hpp"
#include "../include/network.hpp"

using namespace std;

int main() {

    /* variables declaration */
    double baseFirstPosition = 0;
    double baseSecondPosition = 5000;
    double userGeneratorTime;

    Base baseFirst(baseFirstPosition);
    Base baseSecond(baseSecondPosition);
    Simulator simulator;
    Network network;

    simulator.event = false;


    while(1) {

        if(size(network.m_activeUserListInSystem) > 0) {
            /* choose user with the smallest time */
            User actualUser;
            for(const User& user : network.m_activeUserListInSystem) {
                if (user.m_raportTime < actualUser.m_raportTime) {
                    actualUser.m_raportTime = user.m_raportTime;
                }
            }
            if (actualUser.m_raportTime > simulator.m_userGeneratorTime) {
                simulator.m_leastTime = simulator.m_userGeneratorTime;

            } else if (actualUser.m_raportTime < simulator.m_userGeneratorTime){
                simulator.m_leastTime = actualUser.m_raportTime;
            }
            else if (actualUser.m_raportTime == simulator.m_userGeneratorTime) {
                simulator.m_leastTime = simulator.m_userGeneratorTime;
                /* tutaj moliwe ze trzeba na to spojrzec */
            }
        }

        simulator.event = false;
        while(simulator.event == false) {
            simulator.event = true;

            if(simulator.m_userGeneratorTime == simulator.m_leastTime) {
               User* user = new User; 
               user->updateRaportTime(simulator.m_simulatorTime);
               network.addUserToQueue(*user);
               simulator.m_userGeneratorTime = simulator.generateUserAppearanceTime(LAMBDA);
               simulator.updateSimulatorTime(simulator.m_leastTime);
               simulator.event = false;
               
            }

            if(size(network.m_activeUserListInSystem) < 80 && size(network.m_userQueue) > 0) {
                network.addUserToSystem();
                simulator.event = false;
            }
        

        }

        cout << "Kolejka: " << size(network.m_userQueue) << endl;
        cout << "System: "<< size(network.m_activeUserListInSystem) << endl << endl;
        usleep(500000);
    }



    cout << "Before return" << endl;
    return 0;

}