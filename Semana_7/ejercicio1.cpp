/*
Ejercicio 1
Dada una lista ordenada ascendentemente con la función inserInList(nodo **l, int num) hecha en clase,
inviertala mediante la función reverseList(nodo **l).
*/

#include <random>

struct nodeList {
	int val;
	nodeList* next;
};
typedef struct nodeList nodo;

# define MAX 50

void appendToListL(nodo *&l, int num);
void appendToListR(nodo *&l, int num);
void inserInList(nodo *&l, int num);
bool removeFromList(nodo *&l, int num);
void printList(nodo *l);
void reverseList(nodo *&l);

int main(int argc, char **argv) {
	int i, x;
	nodo *miLista = NULL;

	for (i=1; i<=10; i++){
		x = rand()%MAX;
		inserInList(miLista, x);	
	}
    printf("Lista = ");
	printList(miLista);

    reverseList(miLista);
    printf("Lista invertida = ");
    printList(miLista);


	return EXIT_SUCCESS;
}

void reverseList(nodo *&l) {
    return;
}

// elimina el primer nodo de la lista con valor num que encuentra 
// (de izquierda a derecha)
bool removeFromList(nodo *&l, int num) {
	if (l == nullptr)
		return false;

	nodo *p = l;
	if (p->val == num){
		l = p->next;
		delete p;
		return true;
	}

	while(p->next != nullptr && p->next->val != num)
		p = p->next;

	if (p->next != nullptr){
		nodo *q = p->next;		// Este es el nodo que se desea eliminar
		p->next = q->next;
		delete q;
		return true;
	}
	
	return false;
}

// aniade un nodo al inicio de la lista
void appendToListL(nodo *&l, int num) {
	nodo *nuevo = new nodo;
	nuevo->val = num;
	nuevo->next = l;
	l = nuevo;
}

// aniade un nodo al final de la lista
void appendToListR(nodo *&l, int num) {
	nodo *nuevo = new nodo;
	nuevo->val = num;
	nuevo->next = NULL;

	if (l == nullptr)
		l = nuevo;
	else{
		nodo *p = l;
		for(;p->next != nullptr; p = p->next);

		p->next = nuevo;
	}
}

// inserta el nodo en su posicion correcta (ascendente)
void inserInList(nodo *&l, int num) {
	nodo *nuevo = new nodo;
	nuevo->val = num;
	nuevo->next = NULL;

	if (l == nullptr)
		l = nuevo;
	else{
		nodo *p = l;
		if (num <= p->val){
			// se inserta al inicio...
			nuevo->next = p;
			l = nuevo;
		}else{
			for(;p->next != nullptr && p->next->val < num; p=p->next);

			nuevo->next = p->next; // nuevo se inserta justo antes de p->next
			p->next = nuevo;
		}
	}
}

void printList(nodo *l) {
	for(nodo *p = l; p != nullptr; p=p->next){
		printf("%d ",p->val);
	}
	printf("\n");
}
