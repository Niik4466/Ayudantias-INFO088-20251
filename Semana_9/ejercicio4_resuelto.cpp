#include <ios>
#include <stack>
using namespace std;

bool isEmpty(const stack<int> &cola);
void enqueue(stack<int> &cola, const int valor);
int dequeue(stack<int> &cola);
int front(const stack<int> &cola);

int main() {
    //podemos comprobar que es una cola con el siguiente ejemplo:
    //si ingresamos los elementos 1, 2, 3, 4, 5, 6.
    //si fuera una pila, entonces por FIFO debería imprimirse 654321
    //si fuera una cola, entonces por LIFO debería imprimirse 123456

    printf("Creando la Pila...\n");
    stack<int> prueba;
    for (int i = 1; i < 7; ++i)
        prueba.push(i);
    printf("Listo!!!\n\n");

    printf("Creando la Cola...\n");
    stack<int> cola;
    for (int i = 1; i < 7; ++i){
        enqueue(cola, i);
    }
    printf("Listo!!!\n\n");

    printf("Imprimiendo... \n");
    printf("\nPila\tCola\n");
    while (!prueba.empty() || !isEmpty(cola)){
        printf(" %i\t %i\n", prueba.top(), dequeue(cola));
        prueba.pop();
    }

    return EXIT_SUCCESS;
}

//retorna true si la "cola" está vacía, false si no
bool isEmpty(const stack<int> &cola) {
    return (cola.empty());
}

//ingresa un nuevo valor a la "cola"
void enqueue(stack<int> &cola, const int valor) {
    if (cola.empty()){ //si la cola no tiene elementos agregamos uno
        cola.push(valor);
        return;
    }
    //si tiene elementos entonces...
    stack<int> aux;
    while(!cola.empty()){ //damos vuelta la pila llamada "cola" usando una pila "aux"
        aux.push(cola.top());
        cola.pop();
    }
    aux.push(valor);    //de esta manera podemos agregar un elemento por detrás de la pila llamada "cola"
    while (!aux.empty()){//damos vuelta de nuevo la pila
        cola.push(aux.top());
        aux.pop();
    }
    //listo!
}

//elimina un valor de la "cola"
int dequeue(stack<int> &cola) {
    if (cola.empty()) return -1;
    int valor = cola.top();
    cola.pop();
    return valor;
}

//retorna el valor al frente de la "cola"
int front(const stack<int> &cola) {
    if (cola.empty()) return -1;
    return cola.top();
}