/*
Con un vector de enteros aleatorios entre MIN y MAX, A[0..n-1]
cree la función quickSelect(vector<int> &A, const int l, const int r, const int k) el cual encuentre
el k menor elemento del arreglo si estuviese ordenado ascendentemente y retorne su índice

Para crear esta función, apoyese de partition(vector<int> &A, const int l, const int r), función creada
en clases para el algoritmo de quickSort

Pista: al aplicar partition, estamos colocando el elemento del pivote (pv) en su lugar si el array estuviese ordenado,
es decir, el indice arrojado por partition, es el p elemento menor.
*/

#include <vector>
#include <random>
using namespace std;

int quickSelect(vector<int> &A, const int l, const int r, const int k);
int partition(vector<int> &A, const int l, const int r);

#define MIN 10
#define MAX 100

int main(int argc, char **argv){
    

    return EXIT_SUCCESS;
}

int quickSelect(vector<int> &A, const int l, const int r, const int k) {
    return 0;
}

int partition(vector<int> &A, const int l, const int r) {
    return 0;
}