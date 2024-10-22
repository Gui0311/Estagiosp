#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <nlohmann/json.hpp> // Para ler arquivos JSON

using json = nlohmann::json;

int main() {
    std::string filename = "faturamento.json";
    std::ifstream file(filename);
    json data = json::parse(file);

    std::vector<double> faturamentos;
    for (auto& item : data) {
        faturamentos.push_back(item["valor"]);
    }

    // Remover valores nulos ou negativos
    faturamentos.erase(std::remove_if(faturamentos.begin(), faturamentos.end(),
                                     [](double x) { return x <= 0; }),
                      faturamentos.end());

    if (faturamentos.empty()) {
        std::cout << "Não há dados de faturamento válidos." << std::endl;
        return 1;
    }

    double menor = *std::min_element(faturamentos.begin(), faturamentos.end());
    double maior = *std::max_element(faturamentos.begin(), faturamentos.end());
    double media = std::accumulate(faturamentos.begin(), faturamentos.end(), 0.0) / faturamentos.size();

    int dias_acima_media = std::count_if(faturamentos.begin(), faturamentos.end(),
                                       [media](double x) { return x > media; });

    std::cout << "Menor valor: R$" << menor << std::endl;
    std::cout << "Maior valor: R$" << maior << std::endl;
    std::cout << "Dias acima da média: " << dias_acima_media << std::endl;

    return 0;
}