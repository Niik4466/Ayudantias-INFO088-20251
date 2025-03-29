#include <cstdio>
#include <random>

#define MIN 10  //Valor minimo de los números aleatorios
#define MAX 101 //Valor máximo de los números aleatorios

void imprime_array(int *Arr, const int n);
void intercambiar(int *Arr, const int a, const int b);
void mediana(int *Arr, const int n);

int main() {
    //declaramos las variables
    int n;
    //validamos que n sea mayor que 0
    printf("Ingrese n: "); scanf("%d", &n);
    while(n < 1){
        printf("Error! numero ingresado menor o igual a 0, ingrese un numero positivo: "); scanf("%d", &n);
    // Revisar el final del codigo para una explicacion de printf y scanf!!
    }

    //inicialisamos valores
    int *Arr = new int[n];
    for(int i = 0; i<n; ++i ){
        Arr[i] = rand()%(MAX-MIN) + MIN;
    }
    printf("\nArray inicial\n");
    imprime_array(Arr, n);

    mediana(Arr, n);

    printf("\nArray con la mediana centrada\n");
    imprime_array(Arr, n);
    printf("\nLa mediana es aproximadamente %d\n", Arr[(n-1)/2]);

    //eliminamos el Array de memoria
    delete[] Arr;
}

//Coloca nuestra aproximacion de mediana al centro del arreglo
void mediana(int *Arr, const int n) {
    int mid = (n-1)/2;
    if(Arr[0] < Arr[mid]) 
        intercambiar(Arr, 0, mid);

    if(Arr[mid] < Arr[n-1])
        intercambiar(Arr, mid, n-1);
        
    if(Arr[0]<Arr[mid])
        intercambiar(Arr, 0, mid);
}

//Intercambia dos posiciones en un arreglo
void intercambiar(int *Arr, const int a, const int b) {
    int temp = Arr[a];
    Arr[a] = Arr[b];
    Arr[b] = temp;
}


void imprime_array(int *Arr, const int n) {
    for(int i = 0;i<n; ++i){
        printf("%d ", Arr[i]);
    }
    printf("\n");
}

/*
printf es print format, osea que imprime el texto dado con un formato (el texto puede recibir instrucxiones)
    %d le indica al formato que ahi va un digito. Para mas info https://www.simplilearn.com/tutorials/cpp-tutorial/cpp-printf

scanf es scan format, osea que escanea y guarda el buffer de entrada dado un formato.
Para mas info https://www.programiz.com/cpp-programming/library-function/cstdio/scanf
*/
