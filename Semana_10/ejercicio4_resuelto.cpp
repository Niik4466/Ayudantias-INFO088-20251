#include <vector>
#include <queue>
#include <random>

#define MAX 100
#define N 5

struct node{
    node* izq;
    node* der;
    int val;
};

void llenaBST(node** root, int elem);
void transformaArray(node* root, std::vector<int> &BSA, int pos); // Función que transforma un BST a un Array
void print_tree(node **root);
void print_array(std::vector<int> BSA);

// Función que suma si se mueve a la izquierda y reste si se mueve a la derecha
void sumBSA(std::vector<int> &BSA, int &sum, int pos);

int main() {

    node* root = nullptr;
    
    //Poblamos el BST con elementos aleatorios
    for (int i = 0; i < N; ++i) {
        llenaBST(&root, rand()%MAX);
    }
    printf("BST:\n");
    print_tree(&root);
    printf("\n");

    // Calculamos el tamaño del Array
    int max=0;
    for (int i = 0; i<N; ++i) {
        max = max*2+2;
    }
    std::vector<int> BSA(max, -1);
    transformaArray(root , BSA, 0);
    printf("BSA:\n");
    print_array(BSA);

    int sum = 0;
    sumBSA(BSA, sum, 0);
    printf("Las operaciones en el BSA dan: %i\n", sum);
}

void transformaArray(node* root, std::vector<int> &BSA, int pos) {
    if(root == nullptr)
        return;

    BSA.at(pos) = root->val;
    transformaArray(root->izq, BSA, pos*2+1);
    transformaArray(root->der, BSA, pos*2+2);
}

void sumBSA(std::vector<int> &BSA, int &sum, int pos) {
    if(BSA.at(pos) == -1)
        return;
        
    pos%2 == 1 || pos == 0? sum += BSA.at(pos) : sum -= BSA.at(pos);
    sumBSA(BSA, sum, pos*2+1);
    sumBSA(BSA, sum, pos*2+2);
}

void llenaBST(node** root, int elem) {
    if (*root == nullptr){
        (*root) = new node();
        (*root)->val = elem;
    }
    else if ((*root)->val < elem){
        llenaBST(&((*root)->izq), elem);
    }else
        llenaBST(&((*root)->der), elem);
}

void print_tree(node **root) {
    node *temp1;
    std::queue<node*> imprime;
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

void print_array(std::vector<int> BSA) {
    for(int i : BSA)
        printf("%i ", i);
    printf("\n");
}
