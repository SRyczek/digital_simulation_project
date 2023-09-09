
#include "../include/network.hpp"

using namespace std;

Network::Network() {

}

Network::~Network() {

}

void Network::addUserToSystem(User &t_user) {

    if(m_activeUserListInSystem.size() < 80) {
        m_activeUserListInSystem.push_back(t_user);
        cout << "User added" << endl;

    } else {
        cout << "System is full" << endl;
        cout << "Add user to queue" << endl;
        addUserToQueue(t_user);
    }
}

void Network::removeUserFromSytem(User &t_user) {
    if(m_activeUserListInSystem.size() != 0) {
        m_activeUserListInSystem.remove(t_user);
    }

    cout << "Deleted user from system" << endl;
    delete &t_user;
}

void Network::addUserToQueue(User &t_user) {
    m_userQueue.push(t_user);
    cout << "Correctly add user to queue " << endl;

}