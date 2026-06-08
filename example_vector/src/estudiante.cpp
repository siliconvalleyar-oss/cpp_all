#include "estudiante.hpp"
#include <numeric>

double promedio(const std::vector<double>& notas) {
    if (notas.empty()) return 0.0;
    double suma = std::accumulate(notas.begin(), notas.end(), 0.0);
    return suma / notas.size();
}
