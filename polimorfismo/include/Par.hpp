#ifndef PAR_HPP
#define PAR_HPP

#include <iostream>

namespace Estatico {

template <typename T1, typename T2>
class Par {
private:
    T1 primero;
    T2 segundo;

public:
    Par(T1 p, T2 s) : primero(p), segundo(s) {}

    T1 getPrimero() const { return primero; }
    T2 getSegundo() const { return segundo; }

    void mostrar() const {
        std::cout << "(" << primero << ", " << segundo << ")" << std::endl;
    }
};

} // namespace Estatico

#endif // PAR_HPP
