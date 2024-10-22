#include <iostream>
#include <map>

int main() {
    std::map<std::string, double> faturamento_por_estado = {
        {"SP", 67836.43},
        {"RJ", 36678.66},
        // ...
    };

    double total = 0;
    for (auto& estado_faturamento : faturamento_por_estado) {
        total += estado_faturamento.second;
    }

    for (auto& estado_faturamento : faturamento_por_estado) {
        double percentual = (estado_faturamento.second / total) * 100;
        std::cout << estado_faturamento.first << ": " << percentual << "%" << std::endl;
    }

    return 0;
}