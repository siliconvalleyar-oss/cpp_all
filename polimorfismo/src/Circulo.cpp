#include "Circulo.hpp"
#include <iostream>

namespace Dinamico {

Circulo::Circulo(double r) : radio(r) {
    std::cout << "Constructor de Círculo (radio=" << radio << ")" << std::endl;
}

Circulo::~Circulo() {
    std::cout << "Destructor de Círculo" << std::endl;
}

double Circulo::area() const {
    return M_PI * radio * radio;
}

void Circulo::dibujar() const {
    std::cout << "Dibujando un círculo de radio " << radio << std::endl;
}

void Circulo::identificarVptr() const {
    std::cout << "[Círculo] Dirección del objeto: " << this
              << " - vptr apunta a la vtable de Circulo" << std::endl;
}

} // namespace Dinamico
