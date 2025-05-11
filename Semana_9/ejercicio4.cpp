/*
Ejercicio 4: crear una cola utilizando pilas.

Con el uso de la STL <stack> deberá mediante pilas, recrear
el comportamiento de una cola o queue.
Recordar que las pilas tienen una estructura lifo. Last in, first out.
en cambio las colas tienen una estructura fifo. First in, first out.

Para la cola, implementen las funciones "isEmpty()",
"enqueue()", "dequeue()", "front()".


PD: pueden cambiar las declaraciones de las funciones como quieran.

PISTA: esto puede lograrse utilizando dos pilas.
Si cambiamos todos los elementos de una pila a otra, el orden se invierte.
*/
#include <ios>
#include <stack>

bool isEmpty(std::stack<int> cola);
void enqueue(std::stack<int> cola, int valor);
int dequeue(std::stack<int> cola);
int front(std::stack<int> cola);

int main() {

    return EXIT_SUCCESS;
}

//retorna true si la "cola" está vacía, false si no
bool isEmpty(std::stack<int> cola) {
    return false;
}

//ingresa un nuevo valor a la "cola"
void enqueue(std::stack<int> cola, int valor) {
    return;
}

//elimina un valor de la "cola"
int dequeue(std::stack<int> cola) {
    return EXIT_FAILURE;
}

//retorna el valor al frente de la "cola"
int front(std::stack<int> cola) {
    return EXIT_FAILURE;
}
