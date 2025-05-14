#ifndef NEURON
#define NEURON

#include <vector>
using namespace std;

double sigmoid(double x);
double sigmoid_derivated(double x);
double random_value();


class Neuron{
    //private:
    public:
        vector<double> weight;
        double output, bias;
        
    
        Neuron(int nb_input);

        double Activate(const vector<double>&input);
        double setBias();
        //vector<double> getweight(); 
        //double getBias();
        //double getOutput();
        
};



#endif
