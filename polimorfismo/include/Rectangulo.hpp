#ifndef RECTANGULO_HPP
#define RECTANGULO_HPP

#include "Figura.hpp"

namespace Dinamico {

class Rectangulo : public Figura {
private:
    double ancho, alto;

public:
    Rectangulo(double a, double b);
    ~Rectangulo() override;
    double area() const override;
    void dibujar() const override;
};

} // namespace Dinamico

#endif // RECTANGULO_HPP
