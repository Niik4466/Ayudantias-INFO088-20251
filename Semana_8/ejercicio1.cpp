/*
Ejercicio1:
En este ejercicio deberá comprobar si una lista doblemente enlazada que almacena chars es palindrome.

Para hacer esto tiene que crear una lista doblemente enlazada con una palabra leida desde la ejecución del programa (./prog hola)
mediante la función "void appendToList(nodo **l, char letra)" (el como la llena depende de usted)

Luego tiene que crear la función "bool esPalindrome(nodo *l)" la cual recibe una lista doblemente enlazada y retorna true si la palabra es palindrome y
false si no.
*/


#include <string>
using namespace std;

struct nodeList {
    char val;
    nodeList* prev;
    nodeList* next;
};
typedef struct nodeList nodo;

void appendToList(nodo **l, char letra);
void imprimeLista(nodo *l);
bool esPalindrome(nodo *l);

int main(int argc, char** argv){
    
    return EXIT_SUCCESS;
    string s;
    getline(cin, s);
}

void appendToList(nodo **l, char letra) {

}

void imprimeLista(nodo *l){
    for (; l != nullptr; l = l->next) printf("%c ", l->val);
    printf("\n");
}

bool esPalindrome(nodo *l){
    return 1;
}