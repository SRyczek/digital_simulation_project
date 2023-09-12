#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <list>
#include <queue>
#include "user.hpp"

#define X_VALUE 2000

class Network {
public:

    std::list<User> m_activeUserListInSystem;
    std::queue<User> m_userQueue;

    Network();
    ~Network();
    void addUserToSystem();
    void removeUserFromSytem(User &t_user);
    void addUserToQueue(User &t_user);
    void radioLinkBreakup(double t_baseFirstPos, double t_baseSecondPos, User &t_user);
    void userDistanceLimit(double t_baseSecondPos, User &t_user);
private:

};

#endif