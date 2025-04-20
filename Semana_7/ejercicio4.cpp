/*
    Se tiene una lista enlazada de la siguiente forma

    5 -> 7 -> 8 -> x
    |    |    |
    v    v    v
    6 -> 9 -> 10-> x
    |    |    |
    v    v    v
    11-> 12-> 13-> x 
    |    |    |
    v    v    v
    14-> 17-> 20-> x
    |    |    |
    v    v    v
    x    x    x

    (La lista ya esta creada)
    
    Deben codificar la funcion recursiva void setDirections(node *L)
    esta funcion modifica el campo "direction" de la struct node
    en donde "direction" indica la direccion al nodo con mayor numero en el campo "val"
    es decir, si tenemos la siguiente situacion
    
    5 -> 7
    |
    v
    6
    
    Entonces Direction del nodo con valor 5 va a indicar 'r'
    puesto que el nodo con el valor 7 que esta a la derecha es el que tiene mayor valor
    si el nodo con el valor mas grande estuviese abajo, entonces se indicaria 'd'

    -------------------------------------

    En el main deben generar una lista enlazada utilizando la funcion genList() que devuelve un node*
    posteriormente llamar a la funcion setDirections que le dara las direcciones correspondientes a la lista enlazada
    finalmente deben imprimir la lista utilizando void printList(node* L)


    Ejemplo de resultado.
    5(r)  -> 7(d)  -> 8(d)  -> x
    6(d)  -> 9(d)  -> 10(d) -> x
    11(d) -> 12(d) -> 13(d) -> x
    14(r) -> 17(r) -> 20(x) -> x 

*/

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
void setDirections(node &L);

// Imprime la lista enlazada
void printList(node *L);

int main(){

    return 0;

}


void setDirections(node &L){
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

void printList(node *L) {
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
