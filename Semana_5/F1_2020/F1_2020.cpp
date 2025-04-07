#include <iostream>
#include <cstdlib>
using namespace std;
#define MAX 100 

const int M = 6; // Número de filas
const int N = 8; // Número de columnas

void rellenaCeros(int ARR[][N], int M);
void imprimeArreglo(const int ARR[][N], int M);
void rellenaAlternado(int ARR[][N], int M, int d, int t);

int main(int argc, char **argv){
	if(argc != 2){
		cout << "Error. Debe ejecutarse como ./problema d" << endl;
		exit(EXIT_FAILURE);
	}
 // Incluya aquí las funciones y mensajes para saber lo que se está realizando e imprimiendo
 // Recuerde que t es el número aleatorio entre 10 y MAX-1
 // El parámetro d equivale al entero ingresado como argumento en la ejecución del programa
 
	cout << "Fin Formativa 1" << endl;
	return EXIT_SUCCESS;
}

void rellenaCeros(int ARR[][N], int M){

}

void imprimeArreglo(const int ARR[][N], int M){

}

void rellenaAlternado(int ARR[][N], int M, int d, int t){

}

