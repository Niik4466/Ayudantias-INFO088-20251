#include "AVL/AVL.h"
#include <random>

#define MAX 100

void imprimeNodos(nodoAVL* root, int val);

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Se debe ejecutar como './prog n'\n");
        exit(EXIT_FAILURE);
    }

    int n = atoi(argv[1]);

    AVL avl;

    for (int i = 0; i < n; ++i) {
        avl.insert(&(avl.root), rand()%MAX);
    }

    avl.printInorder(avl.root);
    printf("\n");
    imprimeNodos(avl.root->izq, 35);

    return EXIT_SUCCESS;
}

void imprimeNodos(nodoAVL* root, int val) {
    if(root == nullptr)
        return;

    if (root->key == val && root->izq != nullptr && root->izq->der != nullptr) {
		printf("Nodo: %i\nHijo derecho: %i\nHijo derecho del nulo izquierdo %i\n", root->key, root->izq->key, root->izq->der->key);
	} else {
        imprimeNodos(root->izq, val);
        imprimeNodos(root->der, val);
    }
}
