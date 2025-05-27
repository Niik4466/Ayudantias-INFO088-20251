#include "Pila.h"

//Constructor
Pila::Pila() {
    tope = NULL;
}
Pila::Pila(char caracter) {
    tope = new nodo();
    tope->val = caracter;
}

//Destructor
Pila::~Pila() {
    while (!isEmpty())
        pop();
}

//Método de Pila que retorna true si la pila está vacía y false si no.
bool Pila::isEmpty() {
    return tope == NULL;
}

//Método que agrega un valor al tope de la pila
void Pila::push(char caracter) {
    nodo *nuevo = new nodo();
    nuevo->down = tope;
    tope = nuevo;
    tope->val = caracter;
}

//Método que quita un valor del tope de la pila y lo retorna
char Pila::pop() {
    if (tope == NULL) return '\0'; //retorna el caracter nulo 
    nodo *aux = tope;
    char val = tope->val;
    tope = tope->down;
    delete aux;
    return val;
}

//Método que retorna el valor en el tope de la pila
char Pila::top() {
    if (tope == NULL) return '\0';
    return tope->val;
}

//Método que imprime la pila
void Pila::printPila() {
    nodo *aux = tope;
    while (aux != NULL){
        printf("%c", aux->val);
        aux = aux->down;
    }
}