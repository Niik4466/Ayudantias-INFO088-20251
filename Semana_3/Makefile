.PHONY = all clean

# Definir el compilador
CXX=g++

# Definir las banderas de compilación
CXXFLAGS=-std=c++26 -O3 -ffast-math -Wall -Wextra -Wconversion -Wdouble-promotion -Wduplicated-cond -Wfatal-errors -Wfloat-equal -Wformat=2 -Wlogical-op -Wpedantic -Wshadow -Wundef -Wno-unused-parameter -Wno-unused-result

# Definir los archivos fuente
SOURCES:=$(wildcard *.cpp)

# Generar los nombres de los ejecutables en el directorio bin
EXECUTABLES:=$(SOURCES:%.cpp=%)

# Regla para compilar todos los archivos
all: $(EXECUTABLES)


# Regla para compilar cada archivo cpp en su correspondiente binario
%: %.cpp
	$(CXX) $(CXXFLAGS) $? -o $@

# Limpiar los binarios generados
clean:
	@echo " [CLN] Removing binary files"
	rm -rf $(EXECUTABLES)
