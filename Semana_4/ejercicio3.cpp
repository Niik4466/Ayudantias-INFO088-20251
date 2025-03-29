/*
Codifique un programa que lea un entero n positivo mayor que 0,
con la variable n cree un arreglo A[0..n-1] y llenelo con datos aleatorios entre MIN y MAX,
con una variable m guarde el tamaño de su arreglo inicial.

ahora cree la función aumentaCapacidad(int* A, int &n, const int m) que aumente la capacidad de su arreglo en m

Mediante un ciclo for, siga llenando el arreglo hasta 10 veces su capacidad inicial(10*m)

Desafío: probarlo con un n muy grande y medir el tiempo que lleva generar el nuevo arreglo
*/

#include <ios>
#include <random>

#define MAX 10 //Valor máximo posible para el random
#define MIN 10 //Valor mínimo posible para el random

//inicializamos las funciones
int* aumenta_capacidad(int* A, int &n, const int m);
void imprime_array(int *A, int n);

int main() {
    
}
