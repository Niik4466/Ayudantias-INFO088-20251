#include "pila/Pila.h"
using namespace std;

bool esCorrecto(string &palabra);
void llenarPila(Pila &miPila, const string &palabra);

int main(int argc, char** argv) {
    if (argc != 2){
        printf("Debe ejecutarse como ./prog3 palabra\n");
        exit(EXIT_FAILURE);
    }

    string palabra = argv[1];

    printf("%s\n", palabra.c_str());


    if (esCorrecto(palabra))
        printf("Hay un buen uso de los parentesis\n");
    else
        printf("Los parentesis se están utilizando mal :c\n");


    return EXIT_SUCCESS;
}

bool esCorrecto(string &palabra) {
    Pila miPila;
    char c;
    int c_in_palarabra, pos;
    //llenamos la pila
    llenarPila(miPila, palabra);
    while (!miPila.isEmpty())
    {
        c = miPila.pop();
        pos = (int)palabra.find(c);
        switch (c) {
        case '(':
            c_in_palarabra = (int)palabra.find(')', pos+1);
            if(c_in_palarabra == -1)
                return 0;
            palabra.erase(c_in_palarabra, 1);
            palabra.erase(pos, 1);
            break;
        case '[':
            c_in_palarabra = (int)palabra.find(']', pos+1);
            if(c_in_palarabra == -1)
                return 0;
            palabra.erase(c_in_palarabra, 1);
            palabra.erase(pos, 1);
            break;
        case '{':
            c_in_palarabra = (int)palabra.find('}', pos+1);
            if(c_in_palarabra == -1)
                return 0;
            palabra.erase(c_in_palarabra, 1);
            palabra.erase(pos, 1);
            break;
        
        default:
            break;
        }
    }
    if(palabra.empty())
        return 1;
    else
        return 0;
}

void llenarPila(Pila &miPila, const string &palabra) {
    string cierra_parentesis = ")]}";
    for(char c : palabra) {
        if ((int)cierra_parentesis.find(c)==-1) { //si no es simbolo de cierre lo agrega a la pila
            miPila.push(c);
        }
    }
}