# feedforward-cpp

# Feedforward Neural Network in C++

Este projeto é uma implementação simples de uma rede neural feedforward em C++, treinada com backpropagation para aprender a função XOR.

## Objetivo

Demonstrar como uma rede neural multicamada pode ser implementada do zero em C++ sem bibliotecas externas, usando estrutura modular com classes (`Neuron`, `Layer`, `NeuralNetwork`).

---

## Estrutura

feedforward-cpp/
├── include/ #Headers da rede
│ ├── neuron.h
│ ├── layer.h
│ ├── ffn.h
│ └── xor.h
├── src/ #Classes
│ ├── neuron.cpp
│ ├── layer.cpp
│ └── ffn.cpp
├── main.cpp # Execução padrão da rede
├── test_runner.cpp #Roda a rede 5 vezes com diferentes seeds
├── makefile #Compilação
└── resultados_xor.txt #Resultados da execução


---

## Como funciona

A rede é composta por:
- 2 neurônios de entrada
- 1 camada oculta com 2 neurônios
- 1 neurônio de saída
- Função de ativação: Sigmoid
- Algoritmo de treino: Backpropagation

---
## Como compilar
```bash
make all         # Compila os arquivos principais
```
## Como executar
```bash
./feedforward_network
 ```

## Obs:
    - O número de épocas e taxa de aprendizado são ajustáveis em ffn.h.
    - Os pesos são inicializados a cada execução com srand(fixed_seed) para resultados reprodutíveis.

