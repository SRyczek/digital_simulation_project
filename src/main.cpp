
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


    while(simulator.simulatorTime < 1000) {
        cout << "test" << endl;
        /* czy system jest peny i czy kolejka jest pusta itd */

        testUser->updatePosition();
        testUser->changeStation(baseFirst.getPosition(),
                                baseSecond.getPosition(),
                                simulator.simulatorTime);
        network.radioLinkBreakup(baseFirst.getPosition(), baseSecond.getPosition(), *testUser);
        network.userDistanceLimit(baseSecond.getPosition(), *testUser);
                            
        simulator.simulatorTime += 0.02;
    }


    // User testUser;
    // while (testUser.getPosition() < 5000) {
    //     testUser.updatePosition();
    //     cout << "Position: " << testUser.getPosition() << endl;
    //     cout << "Test user power1" << testUser.calculatePower(baseFirst.getPosition()) << endl;
    //     cout << "Test user power2" << testUser.calculatePower(baseSecond.getPosition()) << endl << endl;
    //     usleep(50000);
    // }

    cout << "Before return" << endl;
    return 0;

}