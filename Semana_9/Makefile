# Definir el compilador
CXX = g++

# Definir las banderas de compilación
CXXFLAGS = -Wall -std=c++23

# Definir los archivos fuente
SOURCES = ejercicio1.cpp ejercicio2.cpp ejercicio3.cpp ejercicio4.cpp ejercicio5.cpp

# Generar los nombres de los ejecutables en el directorio bin
EXECUTABLES = $(SOURCES:.cpp=)

# Regla para compilar todos los archivos
all: $(EXECUTABLES)

# Regla para compilar cada archivo cpp en su correspondiente binario
$%:%.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# Limpiar los binarios generados
clean:
	rm -rf $(EXECUTABLES)


