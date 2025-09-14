# Makefile para compilar el proyecto HashTable

# Compilador y flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g

# Archivos fuente y ejecutable
SOURCES = HashTable.cpp main.cpp
HEADERS = HashTable.h
TARGET = hashtable_demo

# Regla principal
all: $(TARGET)

# Compilar el ejecutable
$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)
	@echo "Compilación exitosa. Ejecuta con: ./$(TARGET)"

# Limpiar archivos generados
clean:
	rm -f $(TARGET)
	@echo "Archivos de compilación eliminados"

# Ejecutar el programa
run: $(TARGET)
	./$(TARGET)

# Compilar en modo debug
debug: CXXFLAGS += -DDEBUG
debug: $(TARGET)

# Regla para verificar sintaxis sin compilar
check:
	$(CXX) $(CXXFLAGS) -fsyntax-only $(SOURCES)

# Indicar que estas reglas no crean archivos
.PHONY: all clean run debug check