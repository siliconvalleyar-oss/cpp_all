#include "Figura.hpp"

namespace Dinamico {

Figura::~Figura() {
    std::cout << "Destructor de Figura (base)" << std::endl;
}

void Figura::identificarVptr() const {
    // Esto es solo para ilustrar que cada objeto tiene un vptr.
    // El vptr está oculto; imprimimos la dirección del objeto.
    std::cout << "Dirección del objeto (this): " << this
              << " - Aquí estaría el vptr (oculto)" << std::endl;
}

} // namespace Dinamico
