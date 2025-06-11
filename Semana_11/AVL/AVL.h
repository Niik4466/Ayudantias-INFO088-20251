#include <ios>

struct BinaryNode {
	int key;
	int height;			// altura del nodo
	BinaryNode* izq;
	BinaryNode* der;
};
typedef struct BinaryNode nodoAVL;

class AVL {
public:
	nodoAVL *root;

	AVL();
	virtual ~AVL();

	int getHeight(nodoAVL *nod);
	int getFE(nodoAVL *nod);
	bool insert(nodoAVL **t, int num);
	nodoAVL* leftRotation(nodoAVL *x);
	nodoAVL* rightRotation(nodoAVL *y);
	bool remove(nodoAVL **t, int num);
	bool validaAVL(nodoAVL *t);

	void printInorder(nodoAVL *t);
	void printPreorder(nodoAVL *t);
	void destroyTree(nodoAVL **t);	// usado por el destructor
	nodoAVL *getLowest(nodoAVL *t);
};














