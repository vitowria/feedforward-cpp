#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

#include "neuron.h"

//srand(time(0));

using namespace std;

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}
double sigmoid_derivated(double x) {
    return x * (1.0 - x);
}
double random_value(int fan_in) {
    return ((double)rand() / RAND_MAX - 0.5) * 2.0 / sqrt(fan_in);
}



//Constructor

Neuron::Neuron(int nb_inputs){
    for (int i = 0; i < nb_inputs; i++) {
        weight.push_back(random_value(nb_inputs));
    }
    bias = random_value(nb_inputs);
}


double Neuron::Activate(const vector<double>&input){
    double sum = bias;
    for (size_t i = 0; i < input.size(); i++) {
        sum += weight[i] * input[i];
    }
    output = sigmoid(sum);
    return output; 
}

/*
Neuron::double getBias(){
    return bias;
}

Neuron::double setBias(){
    return bias = random_value();
}

Neuron::double getOutput(){
    return output;
}

*/   