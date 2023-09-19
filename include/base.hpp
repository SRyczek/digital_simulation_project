
#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>

class Base {
public:
    Base(double t_position);
    ~Base();
    double getPosition(void);
private:
    double m_position;

};

#endif