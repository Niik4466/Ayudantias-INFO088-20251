/* 
Se tiene un árbol binario de la siguiente forma:
Cada nodo tiene un puntero al padre.
Los nodos de este arbol fueron guardados en un arreglo de manera aleatorea,
realicen un algoritmo que en base a estos nodos cree el arbol binario con puntero a sus hijos
*/

#include <cstdio>
#include <random>
#include <vector>

#define N 7
#define MAX 50

//estructura del hijo al padre
struct nodoF{
    nodoF* father;
    int val;
};

//estructura del árbol binario
struct nodoQ{
    nodoQ* izq;
    nodoQ* der;
    int val;
};

//Función que crea el arreglo de nodos
void makeArray(std::vector<nodoF*> &nodoArray);

//Función que imprime el arreglo nodoArray
void printArray(std::vector<nodoF*> &nodoArray);

//Función que en base a un arreglo de nodos con puntero al padre crea un árbol binario
void toBinaryTree(std::vector<nodoF*> &nodoArray, nodoQ** root);

int main(int argc, char** argv){
    std::vector<nodoF*> nodoArray(N);
    makeArray(nodoArray);
    printArray(nodoArray);
    nodoQ* root = nullptr;

}

void toBinaryTree(std::vector<nodoF*> &nodoArray, nodoQ** root) {
    //podemos armarlo desde arriba hacia abajo recursivamente para cada sub arbol
    return;
}

void makeArray(std::vector<nodoF*> &nodoArray) {
    nodoF* q;
    
    //Creamos los nodos del arreglo nodoArray
    for (int i = 0; i < N; ++i){
        q = new nodoF();
        q->val = rand() % MAX;
        nodoArray.at(i) = q;
    }

    //Creamos las uniones a mano (quería hacerlo random pero no tuve tiempo para implementarlo bien:c)
    //Imaginemos esto:
    // Al principio tenemos un bósque con muchos árboles los cuales sólo contienen raíces.
    //Para poder armar un árbol único en base a este bósque, entonces debemos ir agregando padres al nodo
    //verificando que para cada nodo p al que le agregamos un padre q, el nodo p no exista en el árbol de q.
    //Si existe el nodo p en el árbol de q, entonces q se cambia a un nuevo nodo aleatorio y se vuelve a repetir el proceso (UNION-FIND).
    nodoArray.at(0)->father = nodoArray.at(1);
    nodoArray.at(1)->father = nullptr;     //nodo raíz
    nodoArray.at(2)->father = nodoArray.at(3);
    nodoArray.at(3)->father = nodoArray.at(4);
    nodoArray.at(4)->father = nodoArray.at(1);
    nodoArray.at(5)->father = nodoArray.at(4);
    nodoArray.at(6)->father = nodoArray.at(3);
}

void printArray(std::vector<nodoF*> &nodoArray) {
    for (int i = 0; i < N; ++i){
        if (nodoArray.at(i)->father == nullptr)
            printf("null\t");
        else
            printf("%i\t", nodoArray.at(i)->father->val);
    }
    printf("\n");
    for (int i = 0; i < N; ++i){
        printf("^\t");
    }
    printf("\n");
    for (int i = 0; i < N; ++i){
        printf("|\t");
    }
    printf("\n");
    for (nodoF* nodo : nodoArray){
        printf("%i\t", nodo->val);
    }
    printf("\n");
}
