#include <iostream>
#include <memory>
#include <vector>

// Incluir cabeceras de polimorfismo estático
#include "Sumador.hpp"
#include "Par.hpp"
#include "Vector2D.hpp"

// Incluir cabeceras de polimorfismo dinámico
#include "Figura.hpp"
#include "Circulo.hpp"
#include "Rectangulo.hpp"

using namespace Estatico;
using namespace Dinamico;

int main() {
    std::cout << "========== POLIMORFISMO ESTÁTICO ==========\n" << std::endl;

    // 1. Plantilla de función
    std::cout << "Suma con plantilla: " << sumar(5, 3) << std::endl;
    std::cout << "Suma con plantilla (double): " << sumar(2.5, 1.7) << std::endl;

    // 2. Plantilla de clase
    Par<int, double> par(10, 3.14);
    std::cout << "Par<int,double>: ";
    par.mostrar();

    // 3. Sobrecarga de operadores
    Vector2D v1(2, 3), v2(4, 1);
    std::cout << "v1 = " << v1 << ", v2 = " << v2 << std::endl;
    std::cout << "v1 + v2 = " << v1 + v2 << std::endl;
    std::cout << "v1 * 3 = " << v1 * 3 << std::endl;
    std::cout << "v1 == v2 ? " << (v1 == v2 ? "true" : "false") << std::endl;

    std::cout << "\n========== POLIMORFISMO DINÁMICO ==========\n" << std::endl;

    // 4. Demostración de vtable y vptr
    // Creamos un vector de punteros a la clase base
    std::vector<std::unique_ptr<Figura>> figuras;
    figuras.push_back(std::make_unique<Circulo>(5.0));
    figuras.push_back(std::make_unique<Rectangulo>(4.0, 6.0));

    // Recorremos y llamamos a métodos virtuales
    for (const auto& fig : figuras) {
        fig->dibujar();           // Resolución dinámica mediante vtable
        std::cout << "Área: " << fig->area() << std::endl;
        fig->identificarVptr();   // Muestra dirección del objeto (y vptr implícito)
        std::cout << "-----------------------" << std::endl;
    }

    // Mostrar información de vtables (concepto)
    std::cout << "\nNOTA: Cada objeto tiene un puntero oculto (vptr) que apunta a la vtable de su clase.\n";
    std::cout << "Las funciones virtuales se resuelven en tiempo de ejecución.\n";

    return 0;
}
