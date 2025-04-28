#include <random>

using namespace std;

struct nodeList {
	int val;
	nodeList* next;
};
typedef struct nodeList nodo;

# define MAX 50

void appendToListL(nodo **l, int num);
void appendToListR(nodo **l, int num);
void inserInList(nodo **l, int num);
bool removeFromList(nodo **l, int num);
void printList(nodo *l);
void separa_pares_impares(nodo **l, nodo **pares, nodo **impares);
void juntar_listas(nodo **listaA, nodo **listaB, nodo **listaAB);

int main(int argc, char **argv){
	int i, x;
	nodo *miLista, *pares, *impares, *miLista2;
    miLista = pares = impares = miLista2 = NULL;

	for (i=1; i<=10; i++){
		x = rand()%MAX;
		inserInList(&miLista, x);	
	}
    printf("Lista = ");
	printList(miLista);

    separa_pares_impares(&miLista, &pares, &impares);
    printf("Pares = ");
    printList(pares);
    printf("Impares = ");
    printList(impares);

    juntar_listas(&pares, &impares, &miLista2);
    printf("Listas reunidas = ");
    printList(miLista2);


	return EXIT_SUCCESS;
}

void separa_pares_impares(nodo **l, nodo **pares, nodo **impares) {
    nodo *parinit, *imparinit; //creamos los nodos que guardaran la primera posicion  de nuestro arreglo de pares e impares
    parinit = imparinit = NULL;
    while(*l != nullptr){ //iteramos por cada elemento dentro de l mientra no sea NULL
        if((*l)->val%2==0){ //comprovamos si es par o impar
            if(*pares == nullptr){ //si el primer elemento es nulo, lo igualamos a *l para evitar errores desegmentation fault
                parinit = *pares = *l;
            } else{ //si no, lo volvemos la siguiente posicion del arreglo
                (*pares)->next = *l;
                *pares = (*pares)->next;
            }
        } else{ //mismo proceso en los impares
            if(*impares == nullptr){
                imparinit = *impares = *l;
            } else{
                (*impares)->next = *l;
                *impares = (*impares)->next;
            }
        }
        *l = (*l)->next;
    }
    (*pares)->next = (*impares)->next = NULL; //hacemos que el ultimo elemento de cada elemento apunte a NULL
    *pares = parinit; //asignamos el puntero a la primera posicion de cada uno
    *impares = imparinit;
}

void juntar_listas(nodo **listaA, nodo **listaB, nodo **listaAB) {
    nodo *initl2 = NULL;
    while(*listaA != nullptr && *listaB != nullptr){ //mientras ninguno de los punteros sea NULL iteramos
        if((*listaA)->val <= (*listaB)->val){ //comprovamos cual es el menor valor
            if(*listaAB == nullptr){ //si la cabecera de la listaAB es nula la igualamos a la cabecera con el menor valor
                *listaAB = initl2 = *listaA;
                *listaA = (*listaA)->next;
            } else{ //si no, agregamos el elemento a la listaAB y nos movemos al siguiente valor
                (*listaAB)->next = *listaA;
                *listaA = (*listaA)->next;
                *listaAB = (*listaAB)->next;
            }
        } else{ //lo mismo si la listaB es menor
            if(*listaAB == nullptr){
                *listaAB = initl2 = *listaB;
                *listaB = (*listaB)->next;
            }
            else{
                (*listaAB)->next = *listaB;
                *listaB = (*listaB)->next;
                *listaAB = (*listaAB)->next;
            }
        }
    }
    if(*listaB == nullptr) //unimos al final de la lista mas larga (y por tanto la que no quedo en NULL al terminar el anterior while)
        (*listaAB)->next = *listaA;
    else
        (*listaAB)->next = *listaB;

    //hacemos que el ultimo valo apunte a NULL, y colocamos el puntero de la listaAB al inicio de la lista
    *listaAB = initl2;
}

bool removeFromList(nodo **l, int num){
	if (*l == nullptr)
		return false;

	nodo *p = *l;
	if (p->val == num){
		*l = p->next;
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

void appendToListL(nodo **l, int num){
	nodo *nuevo = new nodo;
	nuevo->val = num;
	nuevo->next = *l;
	*l = nuevo;
}

void appendToListR(nodo **l, int num){
	nodo *nuevo = new nodo;
	nuevo->val = num;
	nuevo->next = NULL;

	if (*l == nullptr)
		*l = nuevo;
	else{
		nodo *p = *l;
		for(;p->next != nullptr; p = p->next);

		p->next = nuevo;
	}
}

void inserInList(nodo **l, int num){
	nodo *nuevo = new nodo;
	nuevo->val = num;
	nuevo->next = NULL;

	if (*l == nullptr)
		*l = nuevo;
	else{
		nodo *p = *l;
		if (num <= p->val){
			nuevo->next = p;
			*l = nuevo;
		}else{
			for(;p->next != nullptr && p->next->val < num; p=p->next);

			nuevo->next = p->next;
			p->next = nuevo;
		}
	}
}

void printList(nodo *l){
	nodo *p = l;
	for(;p != nullptr; p=p->next){
		printf("%d ",p->val);
	}
	printf("\n");
}