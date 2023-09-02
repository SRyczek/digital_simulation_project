
#include "../include/user.hpp"

using namespace std;

User::User() {
    cout << "Create User" << endl;
    speed = calculateSpeed();
    position = 2000;
}

User::~User() {
    cout << "Deleted user" << endl;
}

double User::calculateSpeed(void) {
    int range = 50 - 5 + 1;
    int num = rand() % range + 5;
    return num * 0.02;
}

void User::updatePosition(void) {
    position += speed;
}