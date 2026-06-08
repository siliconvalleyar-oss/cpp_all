#!/bin/bash

# Crear estructura de directorios
mkdir -p bin include obj src

# Contenido del Makefile
cat > Makefile << 'EOF'
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
TARGET = bin/App
SRC = src/main.cpp
OBJ = obj/main.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

obj/main.o: src/main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
EOF

# Contenido de src/main.cpp (juego Pong ASCII)
cat > src/main.cpp << 'EOF'
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <termios.h>
#include <sys/select.h>

// Dimensiones del campo de juego (se asume terminal con al menos 80x24)
const int WIDTH = 60;
const int HEIGHT = 20;

// Posiciones y velocidades
int ballX, ballY;        // posición de la pelota
int ballDx, ballDy;      // dirección (1 o -1)
int paddle1Y, paddle2Y;  // posición Y de cada paleta (centro de la paleta de 3 bloques)
int score1, score2;      // puntuación

// Estado de la terminal original
struct termios orig_termios;

// Configurar terminal en modo raw (lectura sin bloqueo y sin eco)
void setupTerminal() {
    tcgetattr(STDIN_FILENO, &orig_termios);
    struct termios raw = orig_termios;
    raw.c_lflag &= ~(ICANON | ECHO);
    raw.c_cc[VMIN] = 0;
    raw.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

// Restaurar terminal
void restoreTerminal() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

// Verificar si hay una tecla pulsada (no bloqueante)
bool kbhit() {
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    struct timeval tv = {0, 0};
    select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv);
    return FD_ISSET(STDIN_FILENO, &fds);
}

// Leer un carácter (no bloqueante)
char getch() {
    char c;
    if (read(STDIN_FILENO, &c, 1) > 0) return c;
    return '\0';
}

// Inicializar el juego
void init() {
    ballX = WIDTH / 2;
    ballY = HEIGHT / 2;
    ballDx = 1;
    ballDy = 1;
    paddle1Y = HEIGHT / 2;
    paddle2Y = HEIGHT / 2;
    score1 = 0;
    score2 = 0;
}

// Dibujar todo en la terminal (usando ANSI escape codes)
void draw() {
    // Limpiar pantalla y mover cursor a (0,0)
    std::cout << "\033[2J\033[H";
    
    // Pintar marco superior
    for (int i = 0; i < WIDTH + 2; ++i) std::cout << "#";
    std::cout << "\n";
    
    // Contenido del campo
    for (int y = 0; y < HEIGHT; ++y) {
        std::cout << "#";  // borde izquierdo
        for (int x = 0; x < WIDTH; ++x) {
            if (x == ballX && y == ballY) {
                std::cout << 'O';
            } else if (x == 2 && (y >= paddle1Y - 1 && y <= paddle1Y + 1)) {
                std::cout << '|';  // paleta izquierda
            } else if (x == WIDTH - 3 && (y >= paddle2Y - 1 && y <= paddle2Y + 1)) {
                std::cout << '|';  // paleta derecha
            } else {
                std::cout << ' ';
            }
        }
        std::cout << "#\n";  // borde derecho
    }
    // Pintar marco inferior
    for (int i = 0; i < WIDTH + 2; ++i) std::cout << "#";
    std::cout << "\n";
    
    // Mostrar puntuación
    std::cout << "Jugador 1 (W/S): " << score1 << "   Jugador 2 (O/L): " << score2 << "\n";
    std::cout << "Presiona 'q' para salir\n";
}

// Actualizar lógica y movimiento
void update() {
    // Mover pelota
    ballX += ballDx;
    ballY += ballDy;
    
    // Colisión con bordes superior/inferior
    if (ballY <= 0 || ballY >= HEIGHT - 1) ballDy = -ballDy;
    
    // Colisión con paleta izquierda (x = 2)
    if (ballX == 2 && ballY >= paddle1Y - 1 && ballY <= paddle1Y + 1) {
        ballDx = -ballDx;
        // Ajuste opcional de dirección vertical según punto de impacto
        int hitPos = ballY - paddle1Y;  // -1,0,1
        ballDy = hitPos;
    }
    // Colisión con paleta derecha (x = WIDTH - 3)
    if (ballX == WIDTH - 3 && ballY >= paddle2Y - 1 && ballY <= paddle2Y + 1) {
        ballDx = -ballDx;
        int hitPos = ballY - paddle2Y;
        ballDy = hitPos;
    }
    
    // Marcar punto si sale por izquierda o derecha
    if (ballX < 0) {
        score2++;
        ballX = WIDTH / 2;
        ballY = HEIGHT / 2;
        ballDx = 1; ballDy = 1;
    } else if (ballX >= WIDTH) {
        score1++;
        ballX = WIDTH / 2;
        ballY = HEIGHT / 2;
        ballDx = -1; ballDy = -1;
    }
    
    // Limitar la dirección vertical para que no se quede en 0
    if (ballDy == 0) ballDy = (rand() % 2) ? 1 : -1;
}

int main() {
    setupTerminal();
    init();
    srand(time(nullptr));
    
    bool running = true;
    while (running) {
        // Manejo de entrada (no bloqueante)
        while (kbhit()) {
            char c = getch();
            switch (c) {
                case 'w': case 'W': if (paddle1Y - 1 > 0) paddle1Y--; break;
                case 's': case 'S': if (paddle1Y + 1 < HEIGHT - 1) paddle1Y++; break;
                case 'o': case 'O': if (paddle2Y - 1 > 0) paddle2Y--; break;
                case 'l': case 'L': if (paddle2Y + 1 < HEIGHT - 1) paddle2Y++; break;
                case 'q': running = false; break;
            }
        }
        
        update();
        draw();
        usleep(50000);  // 50 ms entre frames
    }
    
    restoreTerminal();
    std::cout << "\nGracias por jugar. Puntuación final: " << score1 << " - " << score2 << "\n";
    return 0;
}
EOF

echo "Proyecto creado correctamente."
echo "Compila con: make"
echo "Ejecuta con: ./bin/App"
