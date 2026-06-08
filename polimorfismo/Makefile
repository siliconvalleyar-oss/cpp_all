# ============================================================
# Makefile para proyecto de polimorfismo en C++
# ============================================================

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -Iinclude
LDFLAGS =

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Encontrar automáticamente todos los .cpp en src
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))
TARGET = $(BIN_DIR)/programa

all: $(TARGET)

$(TARGET): $(OBJECTS) | $(BIN_DIR)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)

cleanall: clean
	rm -rf $(OBJ_DIR) $(BIN_DIR)

rebuild: cleanall all

debug:
	@echo "SOURCES: $(SOURCES)"
	@echo "OBJECTS: $(OBJECTS)"
	@echo "TARGET: $(TARGET)"

.PHONY: all clean cleanall rebuild debug
