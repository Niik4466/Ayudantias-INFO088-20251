/*
Dada una Matriz dinamica A de caracteres, de tamaño MxN (M filas y N columnas) y un arreglo de 5 caracteres "palabra".
Creen un algoritmo que dada la Matriz de carácteres aleatorios, busque una palabra y la almacene en su primera fila (A[0])

Para esto, primero deben inicializar su matriz y llenarla de carácteres alfabeticos aleatorios. Esto se hace utilizando código ASCII y una transformación de entero a carácter
https://elcodigoascii.com.ar

Luego deben codificar la función booleana encuentra_palabra(char** A)
Esta función debe recorrer cada caracter del arreglo "palabra" y comprobar si existe en la matriz,
de ser ese el caso, va a mover ese caracter a su posición correspondiente en la primera fila de la Matriz.
Simultaneamente, la función debe retornar verdadero si encuentra la palabra o falso si no la encontró.

*/

#include <random>

#define MIN 97  //valor mínimo que pueden tomar los carácteres
#define MAX 123 //valor máximo que pueden tomar los carácteres

#define N 5  //columnas del arreglo
#define M 10 //filas del arreglo

const char palabra[5] = {'z', 'o', 'r', 'r', 'o'}; //palabra a buscar

// Intercambia dos elementos de la matriz
void intercambia_matriz(char** A, int filaA, int columnaA, int filaB, int columnaB);

// Pobla la matriz de elementos
void llena_matriz(char** A);

// Imprime la matriz
void imprime_matriz(char** A);

// Encuentra la palabra dentro de la matriz
bool encuentra_palabra(char** A);

int main() {

}
