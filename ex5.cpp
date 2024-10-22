#include <iostream>
#include <string>

std::string inverter_string(const std::string& str) {
    std::string invertida;
    for (int i = str.length() - 1; i >= 0; i--) {
        invertida += str[i];
    }
    return invertida;
}

int main() {
    std::string texto = "Python";
    std::string texto_invertido = inverter_string(texto);
    std::cout << texto_invertido << std::endl;
    return 0;
}