#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <list>
#include <queue>
#include "../include/user.hpp"

class Network {
public:
    Network();
    ~Network();
    void addUserToSystem(const User &t_user);
    void addUserToQueue(const User &t_user);

private:
    std::list<User> m_activeUserListInSystem;
    std::queue<User> m_userQueue;
};

#endif