#ifndef FNN
#define FNN

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "layer.h"

#define EPOCH 10000
#define LEARNING_TAX 0.1
 


class NeuralNetwork {
    public: 
        Layer hidden_layer;
        Layer output_layer;
    
        NeuralNetwork(int nb_input, int nb_hidden, int nb_output): 
            hidden_layer(nb_hidden, nb_input),
            output_layer(nb_output, nb_hidden){}
    
        vector<double> feedforward(const vector<double>& input);

        void train(const vector<vector<double> >& input, const vector<double>& output); 
 
    };



#endif
