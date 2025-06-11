/*
    Se sabe que un árbol binario puede ser transformado a un vector de la siguiente forma
    para un nodo x ubicado en algún indice i del vector A[1..n] 
    el hijo izquierdo del nodo x estará ubicado en el indice i*2+1
    y el hijo derecho en el indice i*2+2

    Dada esta información y un AVL
    codifique la función void creaAvlVector(nodoAVL* root, int i, vector<int> &vectorAVL)
    ¿Por qué cuesta menos espacio (celdas) transformar un AVL a un vector que un BST a un vector?

    Además codifique la función "void printVectorInorder(vector<int> &vectorAVL, int i)" para imprimir inorder los elementos del vector.
    El resultado de avl.printInorder y printVectorInorder deberían ser el mismo.

    Por último implemente las funciones del ejercicio1.cpp "void imprimeCeldas(nodoAVL* root, int val);"
    y del ejercicio2.cpp "void imprimeAltura(nodo* t, int h);" en su versión vector

    PD: pueden modificar los argumentos de las funciones a conveniencia
*/

#include "AVL/AVL.h"
#include <vector>
#include <random>

#define MAX 100

void creaAvlVector(nodoAVL* root, int i, std::vector<int> vectorAVL);
void imprimeCeldas(std::vector<int> &vectorAVL, int val);
int findMaxHeight(std::vector <int> &vectorAVL, int i);
void imprimeAltura(std::vector<int> &vectorAVL, int h, int i);

int main(int argc, char** argv){
    if (argc != 2){
        printf("Se debe ejecutar como './prog n'\n");
        exit(EXIT_FAILURE);
    }

    int n = atoi(argv[1]);

    AVL avl;

    for (int i = 0; i < n; ++i){
        avl.insert(&(avl.root), rand()%MAX);
    }

    avl.printInorder(avl.root);
    printf("\n");

    std::vector<int> vectorAVL(n, -1);

    return EXIT_SUCCESS;
}

void creaAvlVector(nodoAVL* root, int i, std::vector<int> &vectorAVL) {
    return;
}

void imprimeCeldas(std::vector<int> &vectorAVL, int val) {
    return;
}

int findMaxHeight(std::vector <int> &vectorAVL, int i) {
    return EXIT_SUCCESS;
}

void imprimeAltura(std::vector<int> &vectorAVL, int h, int i) {
    return;
}
