#include "pila/Pila.h"

bool esPalindrome(const string &palabra);

int main(int argc, char** argv) {
    if (argc != 2){
        printf("Debe ejecutarse como ./prog2 palabra\n");
        exit(EXIT_FAILURE);
    }
    string palabra = argv[1];

    if (esPalindrome(palabra))
        printf("La palabra es palindrome!!\n");
    else
        printf("La palabra NO es palindrome!!\n");

}

bool esPalindrome(const string &palabra) {
    //generamos la pila
    Pila miPila;
    for(char c : palabra) {
        miPila.push(c);
    }
    //comprobamos la palabra
    for (char c : palabra) {
        if (miPila.pop() != c){
            return false;
        }
    }

    return true;
}