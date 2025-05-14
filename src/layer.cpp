#include "layer.h"
using namespace std;


Layer::Layer(int nb_neurons, int nb_input_per_neuron) {
    for (int i = 0; i < nb_neurons; i++) {
        neurons.emplace_back(nb_input_per_neuron);
    }
}

vector<double> Layer::feedforward(const vector<double>& input){
    vector<double> output;
    for (auto& n : neurons) {
        output.push_back(n.Activate(input));
    }
    return output;
}
    

