#ifndef CIRCULO_HPP
#define CIRCULO_HPP

#include "Figura.hpp"
#include <cmath>

namespace Dinamico {

class Circulo : public Figura {
private:
    double radio;

public:
    Circulo(double r);
    ~Circulo() override;
    double area() const override;
    void dibujar() const override;
    void identificarVptr() const override;  // Sobrescritura opcional
};

} // namespace Dinamico

#endif // CIRCULO_HPP
