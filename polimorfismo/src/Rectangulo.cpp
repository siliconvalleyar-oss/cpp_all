#include "Rectangulo.hpp"
#include <iostream>

namespace Dinamico {

Rectangulo::Rectangulo(double a, double b) : ancho(a), alto(b) {
    std::cout << "Constructor de Rectángulo (" << ancho << "x" << alto << ")" << std::endl;
}

Rectangulo::~Rectangulo() {
    std::cout << "Destructor de Rectángulo" << std::endl;
}

double Rectangulo::area() const {
    return ancho * alto;
}

void Rectangulo::dibujar() const {
    std::cout << "Dibujando un rectángulo de " << ancho << " x " << alto << std::endl;
}

} // namespace Dinamico
