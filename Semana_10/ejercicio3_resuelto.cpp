#include <queue>
#include <cstdio>

#define N 10

//Struct para el árbol
struct nodoTree{
    char val = '\0'; //inicialmente es el carácter nulo
    nodoTree* izq;
    nodoTree* der;
};

//Struct para la Forma 1
struct nodoList{
    char val;
    nodoList* next;
};

void llenaArbol(nodoTree **root);
void imprimeArbol(nodoTree **root);

int main(int argc, char** argv){
    nodoTree* root = nullptr;
    llenaArbol(&root);

    imprimeArbol(&root);
}

void imprimeArbol(nodoTree **root) {
    nodoTree *temp1;
    std::queue<nodoTree*> imprime;
    imprime.push(*root);
    while(!imprime.empty()) {
        temp1 = imprime.front();
        printf("%c", temp1->val);
        imprime.pop();
        if(temp1->izq != nullptr)
            imprime.push(temp1->izq);
        if(temp1->der != nullptr)
            imprime.push(temp1->der);
    }
    printf("\n");
}

void llenaArbol(nodoTree **root){
    *root = new nodoTree();
    (*root)->val = 'I';
    (*root)->izq = new nodoTree();
    (*root)->izq->izq = new nodoTree();
    (*root)->izq->izq->val = 'L';
    (*root)->izq->izq->izq = new nodoTree();
    (*root)->izq->izq->izq->val = 't';
    (*root)->izq->izq->izq->izq = new nodoTree();
    (*root)->izq->izq->izq->izq->val = 'G';
    (*root)->izq->izq->der = new nodoTree();
    (*root)->izq->izq->der->val = 'h';
    (*root)->izq->izq->der->der = new nodoTree();
    (*root)->izq->izq->der->der->val = 'A';
    (*root)->izq->der = new nodoTree();
    (*root)->izq->der->val = 'O';
    (*root)->izq->der->izq = new nodoTree();
    (*root)->izq->der->izq->val = 'e';
    (*root)->izq->der->izq->izq = new nodoTree();
    (*root)->izq->der->izq->izq->val = 'M';
    (*root)->der = new nodoTree();
    (*root)->der->izq = new nodoTree();
    (*root)->der->izq->val = 'S';
    (*root)->der->izq->izq = new nodoTree();
    (*root)->der->izq->izq->izq = new nodoTree();
    (*root)->der->izq->izq->izq->val = 'E';
    (*root)->der->izq->izq->der = new nodoTree();
    (*root)->der->izq->izq->der->val = ' ';
    (*root)->der->der = new nodoTree();
    (*root)->der->der->val = 'T';
    (*root)->der->der->der = new nodoTree();
    (*root)->der->der->der->izq = new nodoTree();
    (*root)->der->der->der->izq->val = 'X';
    (*root)->der->der->der->der = new nodoTree();
    (*root)->der->der->der->der->val = 'D';
}
