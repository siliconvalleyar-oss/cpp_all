// ============================================================================
// main.cpp - Demostración de métodos de std::vector y contenedores STL
// Cada línea está comentada para explicar su función
// ============================================================================

// Incluye la biblioteca para entrada/salida (cout, endl)
#include <iostream>
// Incluye std::vector (arreglo dinámico)
#include <vector>
// Incluye std::unordered_map (tabla hash)
#include <unordered_map>
// Incluye algoritmos como sort, fill, generate, find, etc.
#include <algorithm>
// Incluye std::accumulate (para sumas y operaciones acumulativas)
#include <numeric>
// Incluye std::string (cadenas de texto)
#include <string>
// Incluye manipuladores de formato como std::fixed, std::setprecision
#include <iomanip>

// Headers propios del proyecto (definidos en include/)
#include "vector_utils.hpp"   // contiene imprimirVector<T>()
#include "estudiante.hpp"     // contiene struct Estudiante y función promedio()
#include "funciones.hpp"      // contiene print_title()

// Usar el espacio de nombres estándar (evita escribir std:: antes de cada cosa)
using namespace std;

// Función principal: punto de entrada del programa
int main() {
    // Imprime un salto de línea inicial para separar del prompt
    cout << "\n";
    // Llama a print_title() que imprime una línea decorativa (═══════...)
    print_title();
    // Imprime el título principal del programa
    cout << "\n  MÉTODOS BÁSICOS DE VECTOR Y STL\n";
    // Imprime otra línea decorativa después del título
    print_title();
    // Salto de línea final para separar del contenido
    cout << endl;

    // ========================== SECCIÓN 1: CONSTRUCTORES ==========================
    cout << "\n1. CONSTRUCTORES\n";
    // Declara un vector de enteros vacío (constructor por defecto)
    vector<int> v1;
    // Declara un vector de 5 elementos, todos inicializados con 10
    vector<int> v2(5, 10);
    // Imprime el vector v2 usando la función auxiliar imprimirVector
    imprimirVector(v2, "v2(5,10)");
    // Declara un vector usando lista de inicialización (C++11)
    vector<int> v3 = {1,2,3,4,5};
    // Imprime v3
    imprimirVector(v3, "v3 lista");

    // ========================== SECCIÓN 2: ACCESO ==========================
    cout << "\n2. ACCESO: front(), back(), at(), []\n";
    // Vector de strings inicializado con tres nombres
    vector<string> nombres = {"Ana","Juan","Carlos"};
    // Imprime el vector
    imprimirVector(nombres, "nombres");
    // Muestra el primer elemento (front) y el último (back)
    cout << "  front(): " << nombres.front() << ", back(): " << nombres.back() << endl;
    // Muestra el elemento en índice 1 usando at() (con verificación de rango) y operador [] (sin verificación)
    cout << "  at(1): " << nombres.at(1) << ", [1]: " << nombres[1] << endl;

    // ========================== SECCIÓN 3: ITERADORES ==========================
    cout << "\n3. ITERADORES begin()/end()\n";
    // Vector de enteros
    vector<int> nums = {10,20,30};
    cout << "  Recorrido normal: ";
    // Recorrido de principio a fin usando iterador begin() y end()
    for (auto it = nums.begin(); it != nums.end(); ++it) 
        cout << *it << " ";   // *it accede al elemento apuntado por el iterador
    cout << "\n  Recorrido inverso (rbegin): ";
    // Recorrido en reversa: rbegin() apunta al último elemento, rend() antes del primero
    for (auto it = nums.rbegin(); it != nums.rend(); ++it) 
        cout << *it << " ";
    cout << endl;

    // ========================== SECCIÓN 4: CAPACIDAD ==========================
    cout << "\n4. CAPACIDAD: size(), capacity(), reserve(), shrink_to_fit()\n";
    // Vector de doubles vacío
    vector<double> med;
    // Reserva espacio para al menos 10 elementos (capacity aumenta, size sigue 0)
    med.reserve(10);
    cout << "  reserve(10) -> capacity = " << med.capacity() << endl;
    // Agrega 5 elementos al final (push_back)
    for (int i = 1; i <= 5; ++i) 
        med.push_back(i * 1.1);
    cout << "  después de 5 push_back: size=" << med.size() << ", cap=" << med.capacity() << endl;
    // Pide al vector que reduzca su capacidad al tamaño actual (libera memoria sobrante)
    med.shrink_to_fit();
    cout << "  shrink_to_fit -> capacity=" << med.capacity() << endl;

    // ========================== SECCIÓN 5: MODIFICADORES ==========================
    cout << "\n5. MODIFICADORES: push_back, emplace_back, insert, erase, pop_back\n";
    vector<string> frutas;                           // vector vacío
    frutas.push_back("Manzana");                     // agrega al final (copia/mueve)
    frutas.emplace_back("Pera");                     // construye directamente al final (más eficiente)
    frutas.emplace_back("kiwi");                     // otro emplace_back
    frutas.push_back("Banana");                      // push_back de otro literal
    frutas.insert(frutas.begin()+1, "Naranja");      // inserta "Naranja" en la posición 1 (segundo lugar)
    imprimirVector(frutas, "frutas");                // muestra el estado actual
    frutas.pop_back();                               // elimina el último elemento ("Banana")
    frutas.erase(frutas.begin());                    // elimina el primer elemento
    imprimirVector(frutas, "después de pop_back y erase");

    // ========================== SECCIÓN 6: ALGORITMOS DE LLENADO ==========================
    cout << "\n6. ALGORITMOS DE LLENADO: fill, fill_n, generate\n";
    vector<int> datos(8);                            // vector de 8 enteros (inicializados a 0)
    fill(datos.begin(), datos.end(), 7);             // llena todo el rango con 7
    cout << "  fill 7: "; for (int x : datos) cout << x << " "; cout << endl;
    fill_n(datos.begin()+2, 3, 99);                  // llena 3 elementos desde la posición 2 con 99
    cout << "  fill_n: "; for (int x : datos) cout << x << " "; cout << endl;
    int cont = 1;                                    // variable contador para generate
    generate(datos.begin(), datos.end(), [&cont]() { return cont++ * 10; }); // lambda que retorna 10,20,30,...
    cout << "  generate: "; for (int x : datos) cout << x << " "; cout << endl;

    // ========================== SECCIÓN 7: UNORDERED_MAP ==========================
    cout << "\n7. UNORDERED_MAP: insert, find, erase\n";
    unordered_map<string, int> edades;               // tabla hash con clave string, valor int
    edades["Ana"] = 25;                              // asignación mediante operador []
    edades.insert({"Luis", 30});                     // inserción con par llave-valor
    edades.emplace("Eva", 28);                       // construye in-place
    cout << "  Mapa: { ";
    for (const auto& p : edades)                     // recorrido: p es un par (clave, valor)
        cout << p.first << ":" << p.second << " ";
    cout << "}\n";
    auto it = edades.find("Luis");                   // busca clave "Luis", retorna iterador
    if (it != edades.end())                          // si no es end(), se encontró
        cout << "  Luis tiene " << it->second << " años\n";
    edades.erase("Ana");                             // elimina la entrada con clave "Ana"
    cout << "  Tras erase(Ana): { ";
    for (const auto& p : edades) cout << p.first << ":" << p.second << " ";
    cout << "}\n";

    // ========================== SECCIÓN 8: ALGORITMOS STL ==========================
    cout << "\n8. ALGORITMOS: sort, reverse, accumulate\n";
    vector<int> vals = {5,2,8,1,4};                  // vector desordenado
    sort(vals.begin(), vals.end());                  // orden ascendente
    cout << "  sort ascendente: "; for (int x : vals) cout << x << " "; cout << endl;
    reverse(vals.begin(), vals.end());               // invierte el orden
    cout << "  reverse: "; for (int x : vals) cout << x << " "; cout << endl;
    int suma = accumulate(vals.begin(), vals.end(), 0); // suma todos los elementos, empezando desde 0
    cout << "  suma = " << suma << endl;

    // ========================== SECCIÓN 9: EJEMPLO PRÁCTICO ==========================
    cout << "\n9. EJEMPLO PRÁCTICO: estudiantes (usando header)\n";
    // Vector de estructuras Estudiante (definida en estudiante.hpp)
    vector<Estudiante> estudiantes = {
        {"Ana", 1001, {85.5, 90.0, 78.5}},
        {"Juan", 1002, {92.0, 88.5, 95.0}}
    };
    // Bucle for-each (C++11) sobre cada estudiante
    for (const auto& e : estudiantes) {
        double prom = promedio(e.notas);            // llama a función promedio definida en estudiante.cpp
        cout << "  " << e.nombre << " (ID " << e.id << ") promedio: "
             << fixed << setprecision(2) << prom << endl; // imprime con 2 decimales
    }

    // ========================== FIN ==========================
    cout << "\n";
    print_title();
    cout << "\n  FIN DE LAS DEMOSTRACIONES\n";
    print_title();
    cout << endl;

    return 0;   // indica que el programa terminó correctamente
}