/*
Con un arreglo A[1..n] ordenado de manera ascendente se pide construir un arbol binario de busqueda
utilizando el algoritmo de busqueda binaria.
Para esto, deben almacenar el elemento en A[(l+r)/2] en un nodo nuevo. El cual sera izquierda o derecha
dependiendo de si la llamada recursiva se realizo en A[l..m-1] (izquierda) o A[m+1..r] (derecha), donde m es (l+r)/2
video de referencia: https://www.instagram.com/reel/C_loDDHh7LD/?igsh=YTAxZHpjNWlxejl3

En el main, deben:
 (1). Crear el vector utilizando void makeOrderedArray(std::vector<int> &A) que ya viene codificado
 (2). Crear el arbol binario de busqueda utilizando la funcion void makeBinaryTree(std::vector<int> &A, int l, int r, nodeTree &*T);

De que manera pueden comprobar que el arbol binario se creo correctamente?
pueden utilizar lo que sea para comprobarlo.
*/

#include <vector>
#include <random>

#define GAP 5 // Espacio entre elementos
#define N 10  // Tamanio del vector

struct nodeTree{
  int val;
  nodeTree *izq;
  nodeTree *der;
};

void makeOrderedArray(std::vector<int> &A);
int binarySearch(const std::vector<int> &A, int l, int r, int x);
void makeBinaryTree(const std::vector<int> &A, int l, int r, nodeTree *&T);

int main(){
  return 0;
}

void makeBinaryTree(const std::vector<int> &A, int l, int r, nodeTree *&T){
  return;
}

int binarySearch(const std::vector<int> &A, int l, int r, int x){
  int m = (l+r)/2;

  if (r < l)
    return -1;

  if (A.at(m) == x)
    return m;

  if (x < A.at(m))
    return binarySearch(A, l, m-1, x); // busca en la mitad izquierda

  return binarySearch(A, m+1, r, x); // busca en la mitad derecha
}

void makeOrderedArray(std::vector<int> &A, int n){
  A.at(0) = rand()%GAP;
  for (int i = 1; i < n; i++)
    A.at(i) = A.at(i-1) + rand()%GAP;
}
