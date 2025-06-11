#include "BST_ADN.h"

BST_ADN::BST_ADN() {
	this->root = NULL;
}

void BST_ADN::eliminarNodos(nodo *t) {
	if (t != nullptr){
		eliminarNodos(t->izq);
		eliminarNodos(t->der);
		delete t;
	}
}

BST_ADN::~BST_ADN() {
	eliminarNodos(root);
}

//============================================
// No acepta claves repetidas
bool BST_ADN::insert(nodo **root, char* word, int m) {
    if (*root == nullptr) {
		*root = new BinaryNode();
        (*root)->m = m;
		(*root)->word = word;
		return true;
	}

	if(compareWords((*root)->word, (*root)->m, word, m) == 1)
		return insert(&((*root)->izq), word, m);
	if(compareWords((*root)->word, (*root)->m, word, m) == -1)
		return insert(&((*root)->der), word, m);

	return false;
}

// Comparación lexicográfica entre dos arreglos de caracteres:
//    Retorna -1 si w1<w2, 0 si son iguales y 1 si w1>w2
//    Si una palabra es prefijo de la otra, entonces la más corta es la menor
int BST_ADN::compareWords(char* w1, int m1, char* w2, int m2) {
    int n = min(m1, m2);
    
    for (int i = 0; i < n; ++i) {
        if (w1[i] < w2[i])
            return -1;
        if (w1[i] > w2[i])
            return 1;
    }
    if (n == m1 && n == m2)
        return 0;
    if(n == m1)
        return 1;

	return -1;
}

void BST_ADN::printInorder(nodo *t) {
	if (t != nullptr) {
		printInorder(t->izq);
		printf("[");
		for (int j=0; j<t->m; j++)
			printf("%c", t->word[j]);
		printf("]\n");
		printInorder(t->der);
	}
}

// cuenta y retorna cuantos caracteres tiene el árbol
int BST_ADN::sizeTree(nodo* t) {
	if (t != nullptr)
		return t->m + sizeTree(t->izq) + sizeTree(t->der);

	return 0;
}