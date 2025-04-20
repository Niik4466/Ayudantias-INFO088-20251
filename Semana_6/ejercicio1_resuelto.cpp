#include <iostream>
#include <cstdlib>
using namespace std;

#define N 20
#define MAX 100

void quickSort(int *A, int l, int r);
int partition(int *A, int l, int r);
void mediana(int *Arr, const int l, const int r);
void intercambiar(int *Arr, const int a, const int b);
void printArray(int *Arr, const int n);

int main(){

    int* Arr;
    Arr = new int[N];

    for (int i = 0; i < N; ++i)
        Arr[i] = rand() % MAX;

    printArray(Arr, N);

    quickSort(Arr, 0, N-1);

    printArray(Arr, N);

    return 0;
}

// Obtiene la aproximacion de la mediana y la deja en (n-1)/2
// La modificamos para que ahora el resultado se calcule en funcion de l y r
void mediana(int *Arr, const int l, const int r) {
    int mid = (l+r)/2;
    if(Arr[l] < Arr[mid]) 
        intercambiar(Arr, l, mid);

    if(Arr[mid] < Arr[r])
        intercambiar(Arr, mid, r);
        
    if(Arr[l]<Arr[mid])
        intercambiar(Arr, l, mid);
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
    // Utilizamos la funcion mediana dada
    mediana(A, l, r);
    // Esto deja nuestra mediana justo en medio, ahora la dejamos en la primera posicion
    swap(A[(l+r)/2], A[r]);
    // Seguimos aplicando partitiony
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

// Imprime el array
void printArray(int *Arr, const int n){
    for (int i = 0; i < n; ++i){
        printf("%i ", Arr[i]);
    }
    printf("\n");
}

