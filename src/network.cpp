
#include "../include/network.hpp"

using namespace std;

Network::Network() {
}

Network::~Network() {
}

void Network::addUserToSystem() {
    User user = m_userQueue.front();
    m_userQueue.pop();
    m_activeUserListInSystem.push_back(user);
}

void Network::removeUserFromSytem(User &t_user) {
    if (m_activeUserListInSystem.size() != 0) {
        m_activeUserListInSystem.remove(t_user);
        cout << "Deleted user from system" << endl;
        delete &t_user;
    }
}

void Network::addUserToQueue(User &t_user) {
    if (&t_user != nullptr) {
        m_userQueue.push(t_user);
        cout << "Correctly add user to queue " << endl;
    }

}

void Network::radioLinkBreakup(double t_baseFirstPos,
                               double t_baseSecondPos,
                               User &t_user) {

    if (t_user.calculatePower(t_baseFirstPos) > (t_user.calculatePower(t_baseSecondPos) + 20) &&
        t_user.calculatePower(t_baseSecondPos) > (t_user.calculatePower(t_baseFirstPos) + 20))
    {
        cout << "Radio link breakup" << endl;
        removeUserFromSytem(t_user);
    }
}

void Network::userDistanceLimit(double t_baseSecondPos, User &t_user) {
    if (t_user.getPosition() < t_baseSecondPos - X_VALUE) {
        cout << "User exceeded the distance limit" << endl;
        removeUserFromSytem(t_user);
    }
}
