
#include <iostream>
#include <assert.h>
#include "../include/user.hpp"


using namespace std;

int main()
{
    User user(2000);

    for(int i = 0; i < 10; i++)
    {
        user.calculatePower(0, 5000);
        //cout << "First base: " << user.m_firstBtsPower << "   ";
        //cout << "Second base: " << user.m_secondBtsPower << "   ";
        
    }

}