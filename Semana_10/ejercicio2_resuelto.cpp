#include <queue>
#include <cstdio>
#include <random>

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
void toBinaryTree(std::vector<nodoF*> &nodoArray, nodoQ** root, nodoF** father);
void print_tree(nodoQ** root);

int main(int argc, char** argv){
    std::vector<nodoF*> nodoArray(N);
    makeArray(nodoArray);
    printArray(nodoArray);
    nodoQ* root = nullptr;
    int pos=0;
    while(nodoArray.at(pos)->father!=nullptr)
        ++pos;
    toBinaryTree(nodoArray, &root, &nodoArray.at(1));
    printf("\nTree:\n");
    print_tree(&root);

}

void toBinaryTree(std::vector<nodoF*> &nodoArray, nodoQ** root, nodoF** father) {
    if (*root == nullptr) {
        *root = new nodoQ;
        (*root)->val = (*father)->val;
    }
    int child = 0;
    for(int i=0; i<N && child<2 ;++i) {
        if(nodoArray.at(i)->father == *father) {
            ++child;
            if(child == 1) {
                (*root)->der = new nodoQ;
                (*root)->der->val = nodoArray.at(i)->val;
                toBinaryTree(nodoArray, &((*root)->der), &nodoArray.at(i));
            }
            if(child == 2) {
                (*root)->izq = new nodoQ;
                (*root)->izq->val = nodoArray.at(i)->val;
                toBinaryTree(nodoArray, &((*root)->izq), &nodoArray.at(i));
            }
        }
    }
}

void makeArray(std::vector<nodoF*> &nodoArray) {
    nodoF* q;
    
    //Creamos los nodos del arreglo nodoArray
    for (int i = 0; i < N; ++i) {
        q = new nodoF();
        q->val = rand() % MAX;
        nodoArray.at(i) = q;
    }

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

void print_tree(nodoQ **root) {
    nodoQ *temp1;
    std::queue<nodoQ*> imprime;
    imprime.push(*root);
    while(!imprime.empty()) {
        temp1 = imprime.front();
        printf("%i ", temp1->val);
        imprime.pop();
        if(temp1->izq != nullptr)
            imprime.push(temp1->izq);
        if(temp1->der != nullptr)
            imprime.push(temp1->der);
    }
    printf("\n");
}
