#include <cstdio>
#include <iostream>

struct node{
    node* right;    // Nodo a la derecha 
    node* down;     // Nodo a la izquierda
    int val;        // Valor del nodo
    char direction; // Direccion al nodo con mayor val 'r' a derecha, 'd' hacia abajo, 'x' si no hay numeros.
    node(int v) : right(nullptr), down(nullptr), val(v), direction('x') {} // Constructor de la struct
};

// Genera la lista enlazada descrita
node* genList();

// Funcion a codificar
void setDirections(node *L);

// Imprime la lista enlazada
void printList(node* L);

int main(){

    node* L = genList();
    setDirections(L);
    printList(L);    

    return 0;

}


void setDirections(node *L){
    // Verificamos los casos de borde
    
    // Si se entrega un puntero nulo
    if(L == nullptr){
        return;
    }

    // Si tiene una direccion no es necesario hacer nada
    if (L->direction != 'x'){
        return;
    }
    
    // Si no tiene nodos adyacentes
    if(L->right == nullptr && L->down == nullptr){
        return;
    }

    // Si no tiene nodo a la derecha, entonces significa que hacia abajo esta el nodo cuyo campo val es el mayor
    if(L->right == nullptr){
        L->direction = 'd';
        setDirections(L->down);
        return;
    }
    // Lo mismo pero hacia abajo
    if (L->down == nullptr){
        L->direction ='r';
        setDirections(L->right);
        return;
    }
    
    // Una vez que hayamos matado todos los casos de borde, podemos hacer lo que queramos sin preocuparnos de que se caiga el programa

    // Verificamos si el nodo ubicado a la derecha del actual, tenga un campo val mayor del que se ubica hacia abajo
    if (L->right->val > L->down->val){
        L->direction = 'r';
    }
    // Si no, entonces significa que hacia abajo esta el nodo con el campo val mayor
    else{
        L->direction = 'd';
    }

    // Posteriormente hacemos la llamada recursiva para seguir llenando el resto de los nodos
    setDirections(L->down);
    setDirections(L->right);

    return;
}

node* genList() {
    //  Creamos los nodos

    // Primera fila
    node* n5 = new node(5);
    node* n7 = new node(7);
    node* n8 = new node(8);

    // Segunda fila
    node* n6 = new node(6);
    node* n9 = new node(9);
    node* n10 = new node(10);

    // Tercera fila
    node* n11 = new node(11);
    node* n12 = new node(12);
    node* n13 = new node(13);

    // Cuarta fila
    node* n14 = new node(14);
    node* n17 = new node(17);
    node* n20 = new node(20);

    //  Enlazamos la lista

    // Enlazar primera fila
    n5->right = n7; n7->right = n8;
    n5->down = n6; n7->down = n9; n8->down = n10;

    // Enlazar segunda fila
    n6->right = n9; n9->right = n10;
    n6->down = n11; n9->down = n12; n10->down = n13;

    // Enlazar tercera fila
    n11->right = n12; n12->right = n13;
    n11->down = n14; n12->down = n17; n13->down = n20;

    // Enlazar cuarta fila
    n14->right = n17; n17->right = n20;

    return n5;
}

void printList(node* L) {
    node* row = L;
    node* col;
    while (row) {
        col = row;
        while (col) {
            printf("%d(%c)\t->\t ", col->val, col->direction);
            col = col->right;
        }
        printf("x\n|\t\t |\t\t |\nv\t\t v\t\t v\n");  // Imprime "x" al final de cada fila
        row = row->down;
    }
    printf("x\t\t x\t\t x\n");
}
