#ifndef ESTUDIANTE_HPP
#define ESTUDIANTE_HPP

#include <string>
#include <vector>

struct Estudiante {
    std::string nombre;
    int id;
    std::vector<double> notas;
};

double promedio(const std::vector<double>& notas);

#endif // ESTUDIANTE_HPP
