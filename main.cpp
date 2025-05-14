/* 
No caso do Feed-Forward temos 5 passos:
Entrada de Dados, Cálculo dos Pesos, Soma Ponderada, Função de Ativação e Saída.
*/

//O cálculo de erro é baseado na diferença entre a saída prevista (calculada) e a saída esperada. 
//Em seguida temos a multiplicação do erro pela derivada da função de ativação.

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "ffn.h"
#include "xor.h"


using namespace std;


int main() {
    freopen("resultados_xor.txt", "w", stdout); 
    //srand(time(0));
    //srand(42);
    vector<int> seeds = {1, 42, 123, 999, 2024};

    NeuralNetwork rnxor(2, 2, 1);

    // Treinar
    auto input = getInput();
    auto output_expected = getExpectedOutput();
    rnxor.train(input, output_expected);

    for (int run = 0; run < seeds.size(); run++) {
            cout << "======== Iteração " << run + 1 << " (seed " << seeds[run] << ") ========" << endl;

            srand(seeds[run]);

            NeuralNetwork rnxor(2, 2, 1);
            auto input = getInput();
            auto output_expected = getExpectedOutput();

            rnxor.train(input, output_expected);

            for (size_t i = 0; i < input.size(); i++) {
                double result = rnxor.feedforward(input[i])[0];
                cout << "Entrada: (" << input[i][0] << ", " << input[i][1] << ") ";
                cout << "→ Saída: " << result << " (esperado: " << output_expected[i] << ")" << endl;
            }

            cout << endl;
        }

    return 0;
}