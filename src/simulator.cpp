
#include "../include/simulator.hpp"

using namespace std;

Simulator::Simulator() {

}

Simulator::~Simulator() {

}

double generateUserAppearanceTime(double t_lambda) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::exponential_distribution<double> dist(t_lambda);
    return dist(gen);
    
}