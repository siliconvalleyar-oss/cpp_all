#!/bin/bash

# ============================================================
# Generador de proyecto C++ - Polimorfismo completo
# Muestra: templates, sobrecarga de operadores, herencia virtual
# Estructura: include/, src/, obj/, bin/, Makefile
# ============================================================

set -e  # Detener en caso de error

# Directorios
INCLUDE_DIR="include"
SRC_DIR="src"
OBJ_DIR="obj"
BIN_DIR="bin"

# Limpiar estructura anterior si existe
rm -rf "$INCLUDE_DIR" "$SRC_DIR" "$OBJ_DIR" "$BIN_DIR" Makefile

# Crear directorios
mkdir -p "$INCLUDE_DIR" "$SRC_DIR" "$OBJ_DIR" "$BIN_DIR"

echo "Generando archivos del proyecto..."

# ============================================================
# 1. include/Sumador.hpp - Plantilla de función (polimorfismo estático)
# ============================================================
cat > "$INCLUDE_DIR/Sumador.hpp" << 'EOF'
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
EOF

# ============================================================
# 2. include/Par.hpp - Plantilla de clase (polimorfismo estático)
# ============================================================
cat > "$INCLUDE_DIR/Par.hpp" << 'EOF'
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
EOF

# ============================================================
# 3. include/Vector2D.hpp - Sobrecarga de operadores (polimorfismo estático)
# ============================================================
cat > "$INCLUDE_DIR/Vector2D.hpp" << 'EOF'
#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP

#include <iostream>

namespace Estatico {

class Vector2D {
private:
    double x, y;

public:
    Vector2D(double x = 0, double y = 0);

    // Sobrecarga de operadores
    Vector2D operator+(const Vector2D& otro) const;
    Vector2D operator-(const Vector2D& otro) const;
    Vector2D operator*(double escalar) const;
    bool operator==(const Vector2D& otro) const;

    friend std::ostream& operator<<(std::ostream& os, const Vector2D& v);

    double getX() const { return x; }
    double getY() const { return y; }
};

} // namespace Estatico

#endif // VECTOR2D_HPP
EOF

# ============================================================
# 4. src/Vector2D.cpp - Implementación de sobrecarga
# ============================================================
cat > "$SRC_DIR/Vector2D.cpp" << 'EOF'
#include "Vector2D.hpp"

namespace Estatico {

Vector2D::Vector2D(double x, double y) : x(x), y(y) {}

Vector2D Vector2D::operator+(const Vector2D& otro) const {
    return Vector2D(x + otro.x, y + otro.y);
}

Vector2D Vector2D::operator-(const Vector2D& otro) const {
    return Vector2D(x - otro.x, y - otro.y);
}

Vector2D Vector2D::operator*(double escalar) const {
    return Vector2D(x * escalar, y * escalar);
}

bool Vector2D::operator==(const Vector2D& otro) const {
    return (x == otro.x) && (y == otro.y);
}

std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

} // namespace Estatico
EOF

# ============================================================
# 5. include/Figura.hpp - Clase base abstracta (polimorfismo dinámico)
# ============================================================
cat > "$INCLUDE_DIR/Figura.hpp" << 'EOF'
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
EOF

# ============================================================
# 6. src/Figura.cpp
# ============================================================
cat > "$SRC_DIR/Figura.cpp" << 'EOF'
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
EOF

# ============================================================
# 7. include/Circulo.hpp
# ============================================================
cat > "$INCLUDE_DIR/Circulo.hpp" << 'EOF'
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
EOF

# ============================================================
# 8. src/Circulo.cpp
# ============================================================
cat > "$SRC_DIR/Circulo.cpp" << 'EOF'
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
EOF

# ============================================================
# 9. include/Rectangulo.hpp
# ============================================================
cat > "$INCLUDE_DIR/Rectangulo.hpp" << 'EOF'
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
EOF

# ============================================================
# 10. src/Rectangulo.cpp
# ============================================================
cat > "$SRC_DIR/Rectangulo.cpp" << 'EOF'
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
EOF

# ============================================================
# 11. src/main.cpp - Demostración de todos los polimorfismos
# ============================================================
cat > "$SRC_DIR/main.cpp" << 'EOF'
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
EOF

# ============================================================
# 12. Makefile profesional
# ============================================================
cat > Makefile << 'EOF'
# ============================================================
# Makefile para proyecto de polimorfismo en C++
# ============================================================

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -Iinclude
LDFLAGS =

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Encontrar automáticamente todos los .cpp en src
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))
TARGET = $(BIN_DIR)/programa

all: $(TARGET)

$(TARGET): $(OBJECTS) | $(BIN_DIR)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)

cleanall: clean
	rm -rf $(OBJ_DIR) $(BIN_DIR)

rebuild: cleanall all

debug:
	@echo "SOURCES: $(SOURCES)"
	@echo "OBJECTS: $(OBJECTS)"
	@echo "TARGET: $(TARGET)"

.PHONY: all clean cleanall rebuild debug
EOF

echo "========================================="
echo "Proyecto generado exitosamente."
echo "Estructura creada:"
echo "  include/  -> archivos .hpp"
echo "  src/      -> archivos .cpp"
echo "  obj/      -> objetos (se crean al compilar)"
echo "  bin/      -> ejecutable"
echo "  Makefile"
echo ""
echo "Para compilar:  make"
echo "Para ejecutar:  ./bin/programa"
echo "Para limpiar:   make clean"
echo "========================================="

