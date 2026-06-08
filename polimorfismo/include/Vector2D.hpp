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
