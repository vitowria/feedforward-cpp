/*Mudular o treinamento*/

#include "ffn.h"
#include <iostream>
#include <vector>

using namespace std;


void NeuralNetwork::train(const vector<vector<double> >& input, const vector<double>& output) {
    for (int epoch_aux = 0; epoch_aux < EPOCH; epoch_aux++) {
        for (size_t i = 0; i < input.size(); i++) {
            // --- FORWARD ---
            vector<double> hidden_output = hidden_layer.feedforward(input[i]);
            vector<double> final_output = output_layer.feedforward(hidden_output);
            /* Depuração 1
            if (epoch_aux % 1000 == 0) {
                cout << "out1: " << final_output[0] << endl;
            }
            */  
            // --- Cálculo do erro da saída ---
            vector<double> output_error;

            for (size_t j = 0; j < final_output.size(); j++) {
                double error = output[i] - final_output[j];
                output_error.push_back(error * sigmoid_derivated(final_output[j]));
            }

            // --- Erro da camada hidden ---
            vector<double> hidden_error(hidden_layer.neurons.size());

            for (size_t j = 0; j < hidden_layer.neurons.size(); j++) {
                double error = 0.0;
                for (size_t k = 0; k < output_layer.neurons.size(); k++) {
                    error += output_error[k] * output_layer.neurons[k].weight[j];
                }
                hidden_error[j] = error * sigmoid_derivated(hidden_layer.neurons[j].output);
            }

            // --- Atualizar pesos camada de saída ---
            for (size_t j = 0; j < output_layer.neurons.size(); j++) {
                for (size_t k = 0; k < output_layer.neurons[j].weight.size(); k++) {
                    output_layer.neurons[j].weight[k] += LEARNING_TAX * output_error[j] * hidden_output[k];
                }
                output_layer.neurons[j].bias += LEARNING_TAX * output_error[j];
            }

        // --- Atualizar peso camada hidden ---
            for (size_t j = 0; j < hidden_layer.neurons.size(); j++) {
                for (size_t k = 0; k < hidden_layer.neurons[j].weight.size(); k++) {
                    hidden_layer.neurons[j].weight[k] +=LEARNING_TAX * hidden_error[j] * input[i][k];
                }
                hidden_layer.neurons[j].bias += LEARNING_TAX * hidden_error[j];
            }
        }
    }
}




vector<double> NeuralNetwork::feedforward(const vector<double>& input) {
    vector<double> hidden = hidden_layer.feedforward(input);
    return output_layer.feedforward(hidden);
}