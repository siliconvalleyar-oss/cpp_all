# cpp_all

Colección de proyectos educativos en C++ que cubren desde fundamentos de STL hasta polimorfismo, plantillas y un juego ASCII.

## Estructura

```
cpp_all/
├── example_database/   # std::vector como base de datos
├── example_vector/     # Tutorial completo de STL (vector, algoritmos)
├── polimorfismo/       # Polimorfismo estático y dinámico
├── pong/               # Juego Pong ASCII en terminal
└── template/           # Herencia con plantillas
```

Cada proyecto sigue la misma estructura interna:

| Directorio  | Propósito                    |
|-------------|------------------------------|
| `src/`      | Código fuente `.cpp`         |
| `include/`  | Cabeceras `.hpp` / `.h`      |
| `obj/`      | Objetos compilados `.o`      |
| `bin/`      | Ejecutable final             |
| `Makefile`  | Configuración de compilación |

## Proyectos

### example_database

Uso de `std::vector` para modelar una base de datos en memoria con el struct `Persona`. Demostración de `push_back`, `emplace_back`, `insert`, `pop_back`, `erase` y `clear`.

```
cd example_database && make && ./bin/programa
```

### example_vector

Tutorial completo de `std::vector` y algoritmos STL: constructores, iteradores, capacidad (`reserve`, `shrink_to_fit`), modificadores, `std::fill`, `std::generate`, `std::sort`, `std::reverse`, `std::accumulate`, y `std::unordered_map`. Incluye un ejemplo práctico de libreta de notas con `struct Estudiante`.

```
cd example_vector && make run
```

### polimorfismo

Demostración de ambos tipos de polimorfismo en C++:

- **Estático** (compile-time): plantillas de función (`Sumador`), plantillas de clase (`Par`), y sobrecarga de operadores (`Vector2D` con `+`, `-`, `*`, `==`, `<<`)
- **Dinámico** (run-time): clase abstracta `Figura` con método virtual puro, derivadas `Circulo` y `Rectangulo`, y demostración de vtable/vptr con `identificarVptr()`

```
cd polimorfismo && make && ./bin/programa
```

El proyecto puede regenerarse desde cero con:
```
cd polimorfismo && bash build_polimorfismo.sh
```

### pong

Juego Pong para dos jugadores en terminal usando modo crudo (`termios`), entrada no bloqueante (`select()`) y códigos ANSI.

- Jugador 1: `W` / `S`
- Jugador 2: `O` / `L`
- `q` para salir

```
cd pong && make && ./bin/App
```

El proyecto puede regenerarse desde cero con:
```
cd pong && bash gen.sh
```

### template

Herencia multinivel con plantillas. `Cabina_t<T>` → `Animals_t<A,B>` → `Home_t<T>`. Demostración de `inline static` para IDs autoincrementales y `emplace_back` vs `push_back`.

```
cd template && make run
```

Compilación con debug:
```
cd template && make debug && ./bin/App
```

## Build System

Compilador: `g++` (estándar) / `clang++` (template)
Estándar: C++17
Flags: `-Wall -Wextra -O2 -Iinclude`

### Comandos comunes

| Comando          | Descripción                                  |
|------------------|----------------------------------------------|
| `make`           | Compilar                                     |
| `make run`       | Compilar y ejecutar                          |
| `make clean`     | Eliminar `.o` y binario                      |
| `make cleanall`  | Eliminar directorios `obj/` y `bin/`         |
| `make rebuild`   | Limpieza total y recompilación               |
| `make debug`     | Compilar con símbolos de depuración          |
| `make valgrind`  | Ejecutar con valgrind (template)             |
