#ifndef SUMADOR_HPP
#define SUMADOR_HPP

namespace Estatico {

// Plantilla de función: funciona con cualquier tipo que tenga operator+
template <typename T>
T sumar(T a, T b) {
    return a + b;
}

} // namespace Estatico

#endif // SUMADOR_HPP
