
#include "../include/base.hpp"

using namespace std;

Base::Base(double t_position) {
    cout << "Create base " << endl;
    m_position = t_position;

}

Base::~Base() {
    cout << "Stacja przestala istniec" << endl;

}


double Base::getPosition() {
    return m_position;
}