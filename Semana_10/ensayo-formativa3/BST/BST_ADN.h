#include <iostream>
#include <cstdlib>

struct BinaryNode {
	char *word;		// clave del nodo
	int m;			// largo del arreglo word
	BinaryNode* izq;
	BinaryNode* der;
};
typedef struct BinaryNode nodo;

class BST_ADN {
public:
	nodo *root;

	BST_ADN();
	void eliminarNodos(nodo *t);
	virtual ~BST_ADN();

	void printInorder(nodo *t);
	bool insert(nodo **t, char* word, int m);
	int compareWords(char* w1, int m1, char* w2, int m2);
	int sizeTree(nodo *t);
};
