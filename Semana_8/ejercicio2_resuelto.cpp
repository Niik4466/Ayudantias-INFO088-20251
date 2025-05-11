#include <random>

struct nodeList {
    char val;
    nodeList* prev;
    nodeList* next;
};
typedef struct nodeList nodo;

#define MAX 100

void appendToList(nodo **l, char num);
void imprimeLista(nodo *l);
void insertionSort_lists(nodo *l);

int main(int argc, char** argv) {
    if(argc != 2){
        fputs_unlocked("Error! debe ejecutarse como ./bin/prog n", stdout);
        return EXIT_FAILURE;
    }
    int n = atoi(argv[1]);

    nodo *l = NULL;
    for(int i=0; i<n; ++i) {
        appendToList(&l, (char)rand()%MAX);
    }
    //imprimimos la lista generada
    imprimeLista(l);

    //aplicamos la función creada
    insertionSort_lists(l);

    //imprimimos la lista resultante
    imprimeLista(l);

}

void insertionSort_lists(nodo *l) {
    l = l->next; //empezamos con el siguiente a l
    char key;
    nodo *j, *k;
    while(l != nullptr) {   //mientras el puntero l no sea nulo, entonces
        key = l->val;       //nuestra key será el valor en la estructura apuntada por l
        j = k = l->prev;    //nuestros punteros j y k son el previo de l. El puntero j será el que recorra la lista y el puntero k será el puntero j en su valor previo a cambiar
        while(j != nullptr && j->val > key) {   //mientras J no sea nulo y el valor en j sea mayor que key entonces
            j->next->val = j->val;  //análogo a A[j+1] = A[j] del algoritmo insertion sort
            k = j;
            j = j->prev;            //avanzamos en la lista
        }
        k->val = key;               //análogo a A[j+1] = key;
        l = l->next;                //avanzamos al siguiente en la lista y volvemos a iterar.
    }
}

void appendToList(nodo **l, char num) {
    if(*l == nullptr) {
        *l = new nodo;
        (*l)->val = num;
    }
    nodo *p = new nodo;
    p->next = *l;
    (*l)->prev = p;
    p->val = num;
    *l = p;
}

void imprimeLista(nodo *l) {
    while(l != nullptr) {
        printf("%i ", l->val);
        l = l->next;
    }
    fputc_unlocked('\n', stdout);
}
