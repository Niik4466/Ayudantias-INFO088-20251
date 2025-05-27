/*
Se sabe que un arbol binario puede representarse en un arreglo BT[1..n] de la siguiente manera
sea un nodo almacenado en el espacio i del arreglo, sus hijos seran BT[i*2+1] y BT[i*2+2]

Dado un árbol binario de búsqueda (BST) deben transformarlo a un Array de la manera antes descrita

Luego, codifiquen la función "void sumBSA(vector<int> Array)" la cual opera con suma si se va al nodo izquierdo y reste si se va al nodo derecho
en postorder.
*/

#include <vector>
#include <random>

#define MAX 100
#define N 5

struct node{
    node* izq;
    node* der;
    int val;
};

void llenaBST(node **root, int elem); // Función para agregar un elemento al BST
void transformaArray(node* root, std::vector<int> BSA /*más argumentos que necesiten*/); // Función que transforma un BST a un Array
void print_tree(node *root);

// Función que suma si se mueve a la izquierda y reste si se mueve a la derecha
void sumBSA(std::vector<int> BSA /*más argumentos que necesiten*/);

int main() {

    node* root = nullptr;
    
    //Poblamos el BST con elementos aleatorios
    for (int i = 0; i < N; ++i) {
        llenaBST(&root, rand()%MAX);
    }
    print_tree(root);
    printf("\n");

    // Calculamos el tamaño del Array
    int max=0;
    for (int i = 0; i<N; ++i) {
        max = max*2+2;
    }

    std::vector<int> BSA(max, -1);
}

void transformaArray(node* root, std::vector<int> BSA) {
    return;
}

void sumBSA(std::vector<int> BSA) {
    return;
}

void llenaBST(node **root, int elem){
    if (*root == nullptr){
        (*root) = new node();
        (*root)->val = elem;
    }
    else if ((*root)->val < elem){
        llenaBST(&(*root)->izq, elem);
    }else
        llenaBST(&(*root)->der, elem);
}

void print_tree(node *root) {
    if(root == NULL)
        return;
    print_tree(root->izq);
    printf("%d ", root->val);
    print_tree(root->der);
}
