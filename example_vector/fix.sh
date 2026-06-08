#!/bin/bash
# fix.sh - Compila y ejecuta el proyecto

set -e

echo "=== LIMPIANDO ==="
make clean

echo "=== COMPILANDO ==="
make

echo "=== EJECUTANDO ==="
./bin/programa
