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

// Para comprobar la correctitud del arbol:
void printInorder(nodeTree *T);

int main(){
  std::vector<int> vec(N);
  makeOrderedArray(vec);

  nodeTree* T;
  makeBinaryTree(vec, 0, N-1, T);

  // Como podemos comprobar la correctitud del arbol?

  // Si imprimos el vector, este estara ordenado. De la misma manera,
  printf("Imprimiendo vector: \t");
  for (const int &val : vec)
    printf("%i ", val);
  printf("\n");

  // Si imprimimos el arbol en Inorder, los elementos deberian aparecer en orden.
  printf("Imprimiendo abb: \t");
  printInorder(T);
  printf("\n");

  // Por tanto si se imprimen los mismos valores, Significa que el arbol binario de busqueda es correcto!!!

  return 0;
}

void makeBinaryTree(const std::vector<int> &A, int l, int r, nodeTree *&T){
  if (r < l)
    return;
  
  int m = (l+r)/2;

  T = new nodeTree();
  T->val = A.at(m);
  makeBinaryTree(A, l, m-1, T->izq);
  makeBinaryTree(A, m+1, r, T->der);
  return;
}

void printInorder(nodeTree *T){
  if (T == nullptr) return;
  printInorder(T->izq);
  printf("%i ", T->val);
  printInorder(T->der);
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

void makeOrderedArray(std::vector<int> &A){
  A.at(0) = rand()%GAP;
  for (int i = 1; i < N; i++)
    A.at(i) = A.at(i-1) + rand()%GAP;
}
