
#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <list>
#include <queue>
#include "user.hpp"

class Network {
public:

    std::list<User> m_activeUserListInSystem;
    std::queue<User> m_userQueue;

    Network();
    ~Network();
    void addUserToSystem();
    void removeUserFromSytem(User &t_user);
    void addUserToQueue(User &t_user);
private:

};

#endif