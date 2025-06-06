#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "ffn.h"
#include "xor.h"


using namespace std;


int main() {
    //freopen("resultados_xor.txt", "w", stdout); 
    srand(time(0));
    
    
    NeuralNetwork rnxor(2, 2, 1);

    // Treinar
    auto input = getInput();
    auto output_expected = getExpectedOutput();
    rnxor.train(input, output_expected);

    // Testar
    for (size_t i = 0; i < input.size(); i++) {
        cout << "Entrada: (" << input[i][0] << ", " << input[i][1] << ") ";
        cout << "→ Saída: " << rnxor.feedforward(input[i])[0] << " (esperado: " << output_expected[i] << ")" << endl;
/*
        auto saida = rnxor.feedforward(input[i]);
        if (saida.empty()) {
            cout << "Erro: saída vazia para entrada (" << input[i][0] << ", " << input[i][1] << ")" << endl;
            continue;
        }
        cout << "→ Saída: " << saida[0] << " (esperado: " << output_expected[i] << ")" << endl;
    }
       */
    }
    return 0;
}