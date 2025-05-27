#ifndef Pila_H
#define Pila_H

#include <ios>
using namespace std;

class Pila{

private:                //Significa que estos elementos o métodos sólo podrán ser accedidos con los métodos definidos publicos y no en el main()
    struct nodoPila{
        char val;
        nodoPila *down;
    };
    typedef struct nodoPila nodo;
    
    nodo *tope;

public:                 //Son todos los elementos o metodos que pueden ser accedidos en el main()
    Pila(); //Constructor
    Pila(char caracter); //Constructor sobrecargado
    virtual ~Pila(); //Destructor

    //Métodos
    bool isEmpty();
    void push(char caracter);
    char pop();
    char top();
    void printPila();
};

#endif