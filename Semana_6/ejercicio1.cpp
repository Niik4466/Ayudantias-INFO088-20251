/*
    Ejercicio 1. Quicksort con mediana aproximada como pivote.

    Se entregan las funciones void mediana(int* Arr, const int n); y Quicksort

    Se pide modificar el algoritmo de Quicksort para hacer que el pivote
    ahora sea el resultado de la funcion mediana(Arr, n);
*/

#include <iostream>
#include <cstdlib>
using namespace std;

void quickSort(int *A, int l, int r);
int partition(int *A, int l, int r);
void mediana(int *Arr, const int n);
void intercambiar(int *Arr, const int a, const int b);

int main(){


    return 0;
}

// Obtiene la aproximacion de la mediana y la deja en (n-1)/2
void mediana(int *Arr, const int n) {
    int mid = (n-1)/2;
    if(Arr[0] < Arr[mid]) 
        intercambiar(Arr, 0, mid);

    if(Arr[mid] < Arr[n-1])
        intercambiar(Arr, mid, n-1);
        
    if(Arr[0]<Arr[mid])
        intercambiar(Arr, 0, mid);
}

// ordena ascendentemente los elementos de A con el algoritmo quickSort
void quickSort(int *A, int l, int r){
	if(l<r){
		int p = partition(A,l,r);
		quickSort(A, l, p-1);
		quickSort(A, p+1, r);
	}
}

int partition(int *A, int l, int r){
	int p = l;
	int pv = A[p];
	for (int i=l+1; i<=r; i++){
		if (A[i] <= pv){
			p++;
			swap(A[i], A[p]);
		}
	}
	swap(A[l], A[p]);
	
	return p;
}

//Intercambia dos posiciones en un arreglo
void intercambiar(int *Arr, const int a, const int b) {
    int temp = Arr[a];
    Arr[a] = Arr[b];
    Arr[b] = temp;
}
