#ifndef LAYER
#define LAYER

#include "neuron.h"
#include <iostream>
#include <vector>
using namespace std;


class Layer {
    public:
        vector<Neuron> neurons;
    
        Layer(int nb_neurons, int nb_input_per_neuron);
    
        vector<double> feedforward(const vector<double>& input);
    };

#endif
