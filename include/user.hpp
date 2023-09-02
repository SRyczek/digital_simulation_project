#ifndef USER_HPP
#define USER_HPP

#include <iostream>

class User {
public:
    User();
    ~User();
    void updatePosition(void);
private:
    double position;
    double speed;

    double calculateSpeed(void);
};


#endif