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
