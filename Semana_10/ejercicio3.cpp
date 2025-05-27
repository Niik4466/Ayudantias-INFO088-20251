/*
Dado un árbol binario desbalanceado que almacena carácteres, deben imprimir todas los caracteres en orden de izquierda a derecha del árbol dependiendo de la altura (imprimen de arriba hacia abajo)

Forma 1: Pueden guardar las palabras en un Array de listas enlazadas donde:
El array es de largo h (donde h es la altura del arbol), luego imprimen el contenido de las listas del array de izquierda a derecha

Forma 2: Pueden con un for desde i=0 hasta h imprimir cada vez que el nodo tenga la altura i

Forma 3: Pueden guardar el nodo raíz en una cola <queue> para luego quitarlo y agregar sus hijos en orden en la cola.

Pueden hacerlo de la forma que quieran, si se les ocurre una mejor, les invito a hacerla
*/
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
}

void imprimeArbol(nodoTree **root) {
    return;
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
