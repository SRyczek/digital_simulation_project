
#include <iostream>
#include <unistd.h>
#include "../include/base.hpp"
#include "../include/user.hpp"

using namespace std;

int main() {
    
    double baseFirstPosition = 0;
    double baseSecondPosition = 5000;
    Base baseFirst(baseFirstPosition);
    Base baseSecond(baseSecondPosition);

    User testUser;

    while (testUser.getPosition() < 5000) {
        testUser.updatePosition();
        cout << "Position: " << testUser.getPosition() << endl;
        cout << "Test user power1" << testUser.calculatePower(baseFirst.getPosition()) << endl;
        cout << "Test user power2" << testUser.calculatePower(baseSecond.getPosition()) << endl << endl;
        usleep(50000);
    }

    return 0;

}