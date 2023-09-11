
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
    User* testUser = new User;

    network.addUserToSystem(*testUser);

    //cout << "Test: " << simulator.generateUserAppearanceTime(LAMBDA) << endl;

    while(1) {

        /* wybierz uzytkownika z najmniejszym czasem */
        testUser->updatePosition();
        simulator.event = false;
        while(simulator.event == false) {
            simulator.event = true;

            if()

            if(testUser->getPosition() > 3000) {
                /* tutaj ogolnie proble, ze jak usune z systemu to dalej na nim sie wywoluje bo jest zwalnianie pamieci */
                network.removeUserFromSytem(*testUser);
                simulator.event = false;
            }

        }


        cout << endl;
        usleep(50000);
    }



    // while(simulator.simulatorTime < 1000) {
    //     cout << "test" << endl;
    //     /* czy system jest peny i czy k olejka jest pusta itd */

    //     testUser->updatePosition();
    //     testUser->changeStation(baseFirst.getPosition(),
    //                             baseSecond.getPosition(),
    //                             simulator.simulatorTime);
    //     network.radioLinkBreakup(baseFirst.getPosition(), baseSecond.getPosition(), *testUser);
    //     network.userDistanceLimit(baseSecond.getPosition(), *testUser);
                            
    //     simulator.simulatorTime += 0.02;
    // }

    cout << "Before return" << endl;
    return 0;

}