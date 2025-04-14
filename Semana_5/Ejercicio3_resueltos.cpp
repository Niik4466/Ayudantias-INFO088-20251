#include <vector>
#include <random>
using namespace std;

int quickSelect(vector<int> &A, int l, int r, const int k);
int partition(vector<int> &A, int l, int r);
int median_aprox(vector<int> &A, const int l, int r);
void print_vec(vector<int> &A);
void quickSort(vector<int> &A, const int l, const int r);

#define MIN 0
#define MAX 100

int main(int argc, char **argv){
    if (argc != 3){
        printf("Error. Debe ejecutarse como ./alum n\n");
        exit(EXIT_FAILURE);
    }

    const int n = atoi(argv[1]), k = atoi(argv[2]);
    if (n < 1 || k < 1){
        printf("n debe ser mayot que 0!!\n");
        exit(EXIT_FAILURE);
    } 

    vector<int> A(n);
    //llenamos el vector utilizando iteradores (ver más aquí -> https://learn.microsoft.com/es-es/cpp/standard-library/iterators?view=msvc-170)
    for (int &iterador: A)
        iterador = MIN + rand()%(MAX-MIN);

    printf("El vector es:\n");
    print_vec(A);
    
    printf("\nEl %d elemento menor es: %d\n", k, quickSelect(A, 0, n-1, k-1));
    
    printf("arreglo ordenado para facil comprobacion:\n");
    quickSort(A, 0, n-1);
    print_vec(A);
    

    return EXIT_SUCCESS;
}

int quickSelect(vector<int> &A, int l, const int r, const int k) {
    //partition deja el 'p' elemento menor en su lugar en la lista
    int p = partition(A, l, r);
    
    // si k = p significa que se encontro el k elemento menor ordenado en la lista
    if(k == p) return A[p];

    // si k < p significa que partition encontró un p elemento mayor al buscado,
    //por lo que nos quedamos con los elementos a la izquierda (menores a p)
    if(k < p)
        return quickSelect(A, l, p-1, k); 
    //si no, significa que partition ordenó un elemento p más pequeño al buscado
    //por lo que nos quedamos con los elementos a la derecha (mayores a p)
    return quickSelect(A, p+1, r, k);
}

//partition, median_aproxy quickSort son adaptaciones de los usados en el anterior ejercicio
int partition(vector<int> &A, const int l ,const int r) {
    const int pivot = median_aprox(A, l, r);
    int rp= r+1;

    for(int j=r;j>l;--j){
        if(A.at(j) > pivot){
            --rp;
            swap(A.at(rp), A.at(j));
        }
    }
    swap(A.at(rp-1), A.at(l));
    return rp-1;
}

int median_aprox(vector<int> &A, const int l, int r) {
    int m = l + (r-l)/2;
    int tmp;

    if (A.at(l) <= A.at(m)){
        if (A.at(r) <= A.at(l)) return A.at(l); /* r l m */
        if (A.at(m) <= A.at(r)) r = m;          /* l m r */
                                                /* l r m */
    } else{
        if (A.at(l) <= A.at(r)) return A.at(l); /* m l r */
        if (A.at(r) <= A.at(m)) r = m;          /* r m l */
                                                /* m r l */
    }
    tmp = A.at(r);
    A.at(r) = A.at(l);
    A.at(l) = tmp;

    return A.at(l);
}

//recorremos el vector con un iterador y imprimimos cada elemento
void print_vec(vector<int> &A) {
    for (int num: A)
        printf("%d ", num);
    printf("\n");
}

void quickSort(vector<int> &A, const int l, const int r) {
    if(l>=r)
        return;
    
    int p = partition(A, l, r);
    quickSort(A, p+1, r);
    quickSort(A, l, p-1);
}