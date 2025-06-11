/*
    Dado un árbol AVL impriman los valores en el siguiente orden
    valor del nodo actual, hijo izquierdo y hijo derecho del hijo izquierdo.
    ¿Que se cumple siempre para cualquier nodo?

    Para imprimirlo deberán codificar la función imprimeNodos(nodoAVL* root, int val) la cual toma un valor cualquiera,
    lo busca en el AVL y posteriormente lo imprime de la manera antes descrita.

    PD: pueden modificar los argumentos de las funciones a conveniencia    
*/

#include "AVL/AVL.h"
#include <random>

#define MAX 100

void imprimeNodos(nodoAVL* root, int val);

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

void imprimeNodos(nodoAVL* root, int val) {
    return;
}
