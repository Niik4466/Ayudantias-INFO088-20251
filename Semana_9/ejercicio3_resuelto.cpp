#include <iostream>
#include <stack>
#include <random>

#define MIN 10
#define MAX 100

int kMenor(std::stack<int> miPila, const int k);
void printPila(const std::stack<int> miPila);

int main() {
    std::stack<int> miPila;

    int n,k;
    n=k=0;

    do{
        std::cout << "Ingrese n>0: "; std::cin >> n;
    } while(n<=0);
    do{
        std::cout << "Ingrese k<n: "; std::cin >> k;
    } while(k >= n);

    for (int i = 0; i < n; ++i){
        miPila.push(rand()%(MAX - MIN) + MIN);
    }

    printf("La pila es: \n");
    printPila(miPila);

    printf("\nEl k-esimo elemento menor es: %i\n", kMenor(miPila, k));

    return EXIT_SUCCESS;
}

int kMenor(std::stack<int> miPila, const int k) {
    std::stack<int> pilaAux;
    int min = -1;
    for (int i = 0; i < k; ++i){ //haremos el proceso de encontrar el minimo k veces
        min = miPila.top();      //el minimo será el tope de la pila miPila
        miPila.pop();            //quitamos un elemento de la pila "miPila"      
        while (!miPila.empty()){ //vacíamos la pila "miPila" de la siguiente manera
            if (miPila.top() < min){ //si el elemento al tope de la pila es menor al min, entonces...
                pilaAux.push(min);  //debemos agregar el minimo anterior a la pila auxiliar para no perder valores
                min = miPila.top(); //cambiar el valor del minimo
            }
            else
                pilaAux.push(miPila.top()); //si el valor no es menor al minimo entonces lo agregamos a la pila auxiliar
            miPila.pop();                   //quitamos un elemento de la pila "miPila"
        }
        miPila.swap(pilaAux);               //notar que el minimo nunca se guardó en pilaAux.
    }
    return min;
}

void printPila(std::stack<int> miPila){
    while (!miPila.empty()){
        printf("%i ", miPila.top());
        miPila.pop();
    }
    printf("\n");
}
