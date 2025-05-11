/*
Ejercicio 2: Verificar que el uso de parentesis sea correcto

En este ejercicio deberán comprobar mediante una pila que el uso de parentesis sea correcto
Entiendase como parentesis (), {}, [].

Para esto deberá crear la función "bool esCorrecto(string palabra)", función que deberá
identificar las aperturas de parentesis en una palabra o texto, guardarlas en una pila
y comprobar que hay una cerradura para las aperturas guardadas.

Ejemplos:
())     INCORRECTO
()(){   INCORRECTO
({)     INCORRECTO
({)}    CORRECTO
{[{}]}  CORRECTO
PD: Son libres de elegir como quieren leer la palabra, pueden modificar la delcaracion de la función esCorrecto dependiendo de sus necesidades.

*/

#include <stack>
#include <string>

bool esCorrecto(std::string palabra);

int main(int argc, char** argv) {

    return EXIT_SUCCESS;
}

bool esCorrecto(std::string palabra) {
    return false;
}
