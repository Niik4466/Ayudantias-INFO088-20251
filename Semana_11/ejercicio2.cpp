/*
    Dado un árbol AVL deben, mediante la función "int findMaxHeight(nodoAVL* t)""
    encontrar la altura máxima del árbol AVL

    posteriormente codificarán la función "void imprimeAltura(nodo* t, int h)"
    a la cual se le dará como argumento el nodo raíz del AVL y una altura random entre 0 y la encontrada.
    la cual imprimirá todos los nodos que tengan la altura h.

    ¿Los valores impresos están ordenados?
    si lo están, ¿Por qué?

    PD: pueden modificar los argumentos de las funciones a conveniencia
*/

#include "AVL/AVL.h"
#include <random>

#define MAX 100

int findMaxHeight(nodoAVL* t);
void imprimeAltura(nodoAVL* t, int h);


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

    return EXIT_SUCCESS;
}

int findMaxHeight(nodoAVL* t) {
    return EXIT_SUCCESS;
}

void imprimeAltura(nodoAVL* t, int h) {
    return;
}
