/*
Dada una lista doblemente enlazada l de tamaño n leido como argumento del programa (./prog n), 
implemente el algoritmo de ordenamiento insertionSort para la lista doblemente-enlazada.

para esto puede apoyarse del pseudocódigo visto en clases

insertionSort(A, n){
    for i = 2 to n do{
        key = A[i]
        j = i − 1
        while(j > 0 AND A[j] > key) do
            A[j + 1] = A[j]
            j = j − 1
        A[j + 1] = key
    }
}
*/

struct nodeList {
    char val;
    nodeList* prev;
    nodeList* next;
};
typedef struct nodeList nodo;

#include <random>
using namespace std;

void appendToList(nodo **l, int num);
void imprimeLista(nodo *l);
void insertionSortList(nodo *l, int n);

int main(int argc, char** argv) {
    return 1;
}

void appendToList(nodo **l, int num) {
    return;
}

void imprimeLista(nodo *l){
    return;
}