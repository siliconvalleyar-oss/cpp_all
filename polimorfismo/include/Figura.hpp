#ifndef FIGURA_HPP
#define FIGURA_HPP

#include <iostream>
#include <memory>

namespace Dinamico {

class Figura {
public:
    virtual ~Figura();                           // Destructor virtual (necesario)
    virtual double area() const = 0;             // Método virtual puro
    virtual void dibujar() const = 0;            // Método virtual puro
    virtual void identificarVptr() const;        // Muestra la dirección del vptr (concepto didáctico)
};

} // namespace Dinamico

#endif // FIGURA_HPP
