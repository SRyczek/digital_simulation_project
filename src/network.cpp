
#include "../include/network.hpp"

using namespace std;

Network::Network()
{
}

Network::~Network()
{
}

void Network::addUserToSystem()
{
    User user = m_userQueue.front();
    m_userQueue.pop();
    m_activeUserListInSystem.push_back(user);
}

void Network::removeUserFromSytem(User &t_user)
{
    if (m_activeUserListInSystem.size() != 0)
    {
        m_activeUserListInSystem.remove(t_user);
        cout << "Deleted user from system" << endl;
    }
}

void Network::addUserToQueue(User &t_user)
{
    if (&t_user != nullptr)
    {
        m_userQueue.push(t_user);
        cout << "Correctly add user to queue " << endl;
    }
}

