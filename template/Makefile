# ============================================================
# Makefile con modo debug explícito
# ============================================================

CXX = clang++
CXXFLAGS_RELEASE = -std=c++17 -Wall -Wextra -O2 -Iinclude
CXXFLAGS_DEBUG   = -std=c++17 -Wall -Wextra -g -O0 -Iinclude
CXXFLAGS = $(CXXFLAGS_RELEASE)   # por defecto

LDFLAGS =

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))
TARGET = $(BIN_DIR)/App

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

run:
	./$(TARGET)
valgrind:
	valgrind --leak-check=full ./$(TARGET)
debug: CXXFLAGS = $(CXXFLAGS_DEBUG)
debug: clean all

.PHONY: all clean cleanall rebuild run debug release