#ifndef VECTOR_UTILS_HPP
#define VECTOR_UTILS_HPP

#include <vector>
#include <iostream>

template<typename T>
void imprimirVector(const std::vector<T>& vec, const std::string& nombre = "Vector") {
    std::cout << nombre << " [";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i + 1 < vec.size()) std::cout << ", ";
    }
    std::cout << "] | tamaño: " << vec.size()
              << " | capacidad: " << vec.capacity() << std::endl;
}

#endif // VECTOR_UTILS_HPP
