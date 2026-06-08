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
