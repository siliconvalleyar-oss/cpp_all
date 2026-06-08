# Makefile para Linux
CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -Iinclude
LD       = g++
LDFLAGS  =

SRCDIR   = src
INCDIR   = include
OBJDIR   = obj
BINDIR   = bin

SOURCES  = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS  = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))
TARGET   = $(BINDIR)/programa

all: $(BINDIR) $(OBJDIR) $(TARGET)

$(BINDIR):
	mkdir -p $(BINDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(TARGET): $(OBJECTS) | $(BINDIR)
	$(LD) $(LDFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)/*.o $(TARGET)

mrproper: clean
	rmdir $(OBJDIR) 2>/dev/null || true
	rmdir $(BINDIR) 2>/dev/null || true

run: all
	./$(TARGET)

.PHONY: all clean mrproper run
