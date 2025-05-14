#ifndef XOR_H
#define XOR_H

#include <vector>
using namespace std;

inline vector<vector<double> > getInput() {
    vector<vector<double> > input;
    input.push_back({0, 0});
    input.push_back({0, 1});
    input.push_back({1, 0});
    input.push_back({1, 1});
    return input;
}

inline vector<double> getExpectedOutput() {
    vector<double> output;
    output.push_back(0);
    output.push_back(1);
    output.push_back(1);
    output.push_back(0);
    return output;
}

#endif

