---
name: cpp-project
description: Skill para el proyecto cpp_all — colección de proyectos educativos C++ con Makefiles
---

# Proyecto: cpp_all

Repositorio en `/mnt/disk/src/cpp_all` con 5 subproyectos C++ educativos.

## Estructura general

```
cpp_all/
├── example_database/   # std::vector como base de datos
│   ├── src/main.cpp
│   ├── include/
│   ├── obj/            # ignorado por git
│   ├── bin/            # ignorado por git
│   └── Makefile
├── example_vector/     # Tutorial STL (vector, algoritmos, unordered_map)
│   ├── src/main.cpp, src/estudiante.cpp, src/funciones.cpp
│   ├── include/vector_utils.hpp, include/estudiante.hpp, include/funciones.hpp
│   ├── fix.sh          # make clean && make && run
│   ├── obj/, bin/
│   └── Makefile
├── polimorfismo/       # Polimorfismo estático + dinámico
│   ├── src/ (main.cpp, Vector2D.cpp, Figura.cpp, Circulo.cpp, Rectangulo.cpp)
│   ├── include/ (Sumador.hpp, Par.hpp, Vector2D.hpp, Figura.hpp, Circulo.hpp, Rectangulo.hpp)
│   ├── build_polimorfismo.sh  # regenera TODO el proyecto desde heredocs
│   ├── obj/, bin/
│   └── Makefile
├── pong/               # Juego Pong ASCII en terminal
│   ├── src/main.cpp    # ~165 líneas, todo en un archivo
│   ├── gen.sh          # regenera TODO el proyecto desde heredocs
│   ├── obj/, bin/
│   └── Makefile
├── template/           # Herencia multinivel con plantillas
│   ├── src/main.cpp
│   ├── include/cabin.h
│   ├── obj/, bin/
│   └── Makefile        # clang++, targets debug/valgrind
├── README.md
├── .gitignore          # *.o, *.a, *.so, *.exe, bin/, obj/, editor/OS files
└── .opencode/
    └── skills/cpp-project/skill.md
```

## Convenciones del proyecto

### Directorios estándar en cada subproyecto
- `src/` — código fuente `.cpp`
- `include/` — cabeceras `.hpp` / `.h`
- `obj/` — objetos compilados (ignorados por git)
- `bin/` — ejecutables (ignorados por git)
- `Makefile` — build config

### Build system
- Compilador: `g++` (por defecto), `clang++` (template)
- Estándar: `-std=c++17`
- Flags: `-Wall -Wextra -O2 -Iinclude`
- Auto-descubrimiento de fuentes con `wildcard` y `patsubst`
- Directorios creados con order-only prerequisites (`|`)

### Comandos disponibles por proyecto
| Comando | example_database | example_vector | polimorfismo | pong | template |
|---------|:---:|:---:|:---:|:---:|:---:|
| `make` | ✓ | ✓ | ✓ | ✓ | ✓ |
| `make run` | ✓ | ✓ | ✗ | ✗ | ✓ |
| `make clean` | ✓ | ✓ | ✓ | ✓ | ✓ |
| `make cleanall` | ✗ | ✗ | ✓ | ✗ | ✓ |
| `make rebuild` | ✗ | ✗ | ✓ | ✗ | ✓ |
| `make debug` | ✗ | ✗ | ✗ | ✗ | ✓ |
| `make valgrind` | ✗ | ✗ | ✗ | ✗ | ✓ |

## Scripts generadores

Dos proyectos contienen scripts que regeneran **todo** el código fuente desde heredocs:

- `polimorfismo/build_polimorfismo.sh` — ~440 líneas, genera toda la estructura y todos los archivos
- `pong/gen.sh` — genera Makefile y src/main.cpp

Estos scripts son la fuente canónica de esos proyectos.

## Reglas importantes

- **Nunca subir archivos `.o`, `bin/` o `obj/`** — ya están en `.gitignore` y removidos del tracking
- **No modificar los scripts generadores** a menos que se quiera cambiar la fuente canónica
- Si se editan archivos generados por scripts, considerar si el script también debe actualizarse
- Preferir español para mensajes de commit y documentación
- `g++` es el compilador estándar, solo `template/` usa `clang++`
