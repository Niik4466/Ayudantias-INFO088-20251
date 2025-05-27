#include "BST_ADN.h"

BST_ADN::BST_ADN() {
	this->root = NULL;
}


void BST_ADN::eliminarNodos(nodo *t){
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
bool BST_ADN::insert(nodo **t, char* word, int m){
	
	return false;
}


// Comparación lexicográfica entre dos arreglos de caracteres:
//    Retorna -1 si w1<w2, 0 si son iguales y 1 si w1>w2
//    Si una palabra es prefijo de la otra, entonces la más corta es la menor
int BST_ADN::compareWords(char* w1, int m1, char* w2, int m2){

	return 0;
}


void BST_ADN::printInorder(nodo *t){
	if (t != nullptr){
		printInorder(t->izq);
		std::cout << "[";
		for (int j=0; j<t->m; j++)
			std::cout << t->word[j];
		std::cout << "]" << std::endl;
		printInorder(t->der);
	}
}

// cuenta y retorna cuantos caracteres tiene el árbol
int BST_ADN::sizeTree(nodo* t){
	if (t != nullptr)
		return t->m + sizeTree(t->izq) + sizeTree(t->der);

	return 0;
}

