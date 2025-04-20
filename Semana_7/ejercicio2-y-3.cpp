/*
Ejercicio 2
Dada una lista enlazada ordenada ascendentemente con n elementos,
separe los elementos de la lista que sean pares en una lista e impares en otra en la funcion separa_pares_impares(nodo **l, nodo **pares, nodo **impares).

Ejercicio 3
Teniendo las listas de pares e impares del ejercicio 2
ahora debe unirlas en una nueva lista manteniendo el orden original en la funcion juntar_listas(nodo **pares, nodo **impares, nodo **l2).
*/

#include <random>

using namespace std;

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
void separa_pares_impares(nodo *&l, nodo *&pares, nodo *&impares);
void juntar_listas(nodo *&pares, nodo *&impares, nodo *&l2);

int main(int argc, char **argv){
	int i, x;
	nodo *miLista, *pares, *impares, *miLista2;
    miLista = pares = impares = miLista2 = NULL;

	for (i=1; i<=10; i++){
		x = rand()%MAX;
		inserInList(miLista, x);	
	}
    printf("Lista = ");
	printList(miLista);



	return EXIT_SUCCESS;
}

void separa_pares_impares(nodo *&l, nodo *&pares, nodo *&impares) {
    return;
}

void juntar_listas(nodo *&pares, nodo *&impares, nodo *&l2) {
    return;
}

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
		nodo *q = p->next;
		p->next = q->next;
		delete q;
		return true;
	}
	
	return false;
}

void appendToListL(nodo *&l, int num) {
	nodo *nuevo = new nodo;
	nuevo->val = num;
	nuevo->next = l;
	l = nuevo;
}

void appendToListR(nodo *&l, int num) {
	nodo *nuevo = new nodo;
	nuevo->val = num;
	nuevo->next = NULL;

	if (l == nullptr)
		l = nuevo;
	else{
		nodo *p = l;
		while(p->next != nullptr)
            p = p->next;

		p->next = nuevo;
	}
}

void inserInList(nodo *&l, int num) {
	nodo *nuevo = new nodo;
	nuevo->val = num;
	nuevo->next = NULL;

	if (l == nullptr)
		l = nuevo;
	else{
		nodo *p = l;
		if (num <= p->val){
			nuevo->next = p;
			l = nuevo;
		}else{
			while(p->next != nullptr && p->next->val < num)
                p=p->next;

			nuevo->next = p->next;
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
