#include "AVL/AVL.h"
#include <random>

#define MAX 100

int findMaxHeight(int n);
void imprimeAltura(nodoAVL* t, int h);

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

    int h = findMaxHeight(n);
    imprimeAltura(avl.root, rand()%h);
    printf("\n");

    return EXIT_SUCCESS;
}   

int findMaxHeight(const int n) {
    return static_cast<int>(floor(log2(n)));
}

void imprimeAltura(nodoAVL* t, int h) {
    if (t == nullptr)
        return;
    
    imprimeAltura(t->izq, h);
    if (t->height == h)
        printf("%i ", t->key);
    imprimeAltura(t->der, h);
}
