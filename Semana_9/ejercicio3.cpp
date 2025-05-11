/*
Ejercicio 3: Encontrar el k-esimo elemento menor

Mediante el uso de la STL <stack> deberá crear una pila y rellenarla 
con números aleatorios entre MIN y MAX

para encontrar el k-esimo elemento menor deberá codificar 
la función "int kMenor(stack<int> pila, int k)"
la cual recibe la pila generada y el entero k.
Esta debe encontrar el menor y eliminarlo k-1 veces, luego busca el menor y lo devuelve
Puede usar otra Pila de apoyo.

*/

#include <stack>
#include <ios>

#define MIN 10
#define MAX 100

int kMenor(std::stack<int> pila, int k);

int main(){

    return EXIT_SUCCESS;
}

int kMenor(std::stack<int> pila, int k){
    return -1;
}
