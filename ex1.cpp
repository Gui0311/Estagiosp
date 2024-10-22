#include <iostream>

int main() {
    int INDICE = 13, SOMA = 0, K = 0;
    while (K < INDICE) {
        K = K + 1;
        SOMA = SOMA + K;
    }
    std::cout << "A soma é: " << SOMA << std::endl;
    return 0;
}

//Imprime o numero 78 .