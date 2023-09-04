
#include <iostream>
#include "../include/base.hpp"
#include "../include/user.hpp"

using namespace std;

int main() {
    
    double baseFirstPosition = 0;
    double baseSecondPosition = 5000;
    Base baseFirst(baseFirstPosition);
    Base baseSecond(baseSecondPosition);

    User testUser;

    while(testUser.getPosition() < 5000) {
        testUser.updatePosition();
        cout << "Test user power" << testUser.calculatePower(baseFirst.getPosition()) << endl;

    }

    return 0;

}