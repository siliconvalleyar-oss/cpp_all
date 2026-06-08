#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

// Estructura que representa una persona
struct Persona {
    std::string nombre;
    std::string apellido;
    int edad;
    std::string telefono;

    // Constructor para facilitar el uso con emplace_back
    Persona(const std::string& n, const std::string& a, int e, const std::string& t)
        : nombre(n), apellido(a), edad(e), telefono(t) {}

    // Método para mostrar los datos de la persona
    void mostrar() const {
        std::cout << std::left << std::setw(10) << nombre
                  << std::setw(10) << apellido
                  << std::setw(5) << edad
                  << std::setw(12) << telefono << std::endl;
    }
};

// Función para imprimir todo el vector de personas
void imprimirBase(const std::vector<Persona>& db, const std::string& titulo) {
    std::cout << "\n--- " << titulo << " ---\n";
    std::cout << std::left << std::setw(10) << "Nombre"
              << std::setw(10) << "Apellido"
              << std::setw(5) << "Edad"
              << std::setw(12) << "Teléfono" << std::endl;
    std::cout << "--------------------------------------\n";
    for (const auto& p : db) {
        p.mostrar();
    }
    std::cout << "Total: " << db.size() << " personas\n";
}

int main() {
    std::vector<Persona> personas;   // vector vacío

    // 1. push_back: agregar al final
    personas.push_back(Persona("Juan", "Perez", 25, "555-1234"));
    personas.push_back(Persona("Maria", "Gomez", 30, "555-5678"));
    imprimirBase(personas, "Después de push_back (Juan y Maria)");

    // 2. emplace_back: construye directamente en el vector (más eficiente)
    personas.emplace_back("Carlos", "Lopez", 28, "555-9012");
    personas.emplace_back("Ana", "Martinez", 22, "555-3456");
    imprimirBase(personas, "Después de emplace_back (Carlos y Ana)");

    // 3. insert: insertar en una posición específica
    // Insertar a Luis en la posición 1 (segundo lugar)
    auto it = personas.begin() + 1;
    personas.insert(it, Persona("Luis", "Rodriguez", 35, "555-7890"));
    imprimirBase(personas, "Después de insert (Luis en posición 1)");

    // 4. pop_back: eliminar el último elemento
    personas.pop_back();  // elimina a Ana
    imprimirBase(personas, "Después de pop_back (se fue Ana)");

    // 5. erase: eliminar por posición o rango
    // Eliminar al primer elemento (Juan)
    personas.erase(personas.begin());
    imprimirBase(personas, "Después de erase (se fue Juan)");

    // Eliminar un rango: desde posición 1 hasta antes del final (2 elementos: Maria y Carlos)
    personas.erase(personas.begin() + 1, personas.end() - 1);
    imprimirBase(personas, "Después de erase rango (quedan solo Luis y Maria?)");
    // Nota: después de erase rango, deberían quedar Luis (índice 0) y Maria (índice 1 original? Veamos el estado real)

    // Mejor mostrar el estado después de cada operación para claridad.
    // Volvamos a crear un ejemplo limpio y paso a paso sin confusión:

    std::cout << "\n\n========== DEMOSTRACIÓN CLARA PASO A PASO ==========\n";
    std::vector<Persona> db;

    // Agregar usando push_back
    db.push_back(Persona("Alberto", "Fernandez", 40, "111-1111"));
    db.push_back(Persona("Brenda", "Garcia", 32, "222-2222"));
    imprimirBase(db, "Paso 1: push_back dos personas");

    // Agregar usando emplace_back
    db.emplace_back("Carlos", "Hernandez", 27, "333-3333");
    imprimirBase(db, "Paso 2: emplace_back una persona");

    // Insertar en la posición 1 (entre Alberto y Brenda)
    db.insert(db.begin() + 1, Persona("David", "Luna", 45, "444-4444"));
    imprimirBase(db, "Paso 3: insert en índice 1");

    // Modificar un elemento existente (cambiar teléfono de Brenda)
    db[2].telefono = "999-9999";   // Brenda está en índice 2 ahora
    db[2].edad = 33;
    imprimirBase(db, "Paso 4: modificar Brenda (nuevo teléfono y edad)");

    // Eliminar el último elemento (Carlos) con pop_back
    db.pop_back();
    imprimirBase(db, "Paso 5: pop_back (se fue Carlos)");

    // Eliminar un elemento específico (David en índice 1) con erase
    db.erase(db.begin() + 1);
    imprimirBase(db, "Paso 6: erase (se fue David)");

    // Limpiar toda la base de datos
    db.clear();
    imprimirBase(db, "Paso 7: clear (base vacía)");

    // Verificar que está vacía
    std::cout << "\n¿Base vacía? " << (db.empty() ? "Sí" : "No") << std::endl;

    return 0;
}
