#include <cstring>
#include <random>
#include <vector>
#include <array>
using namespace std;

#define N_CAR 3
#define N_NOM 5
#define N_APEL 10
#define MIN_EDAD 17
#define MAX_EDAD 49

const array<char[10], N_NOM>  ellos = {"Pedro", "Juan", "Manuel", "Diego", "Agustin"};
const array<char[10], N_NOM> ellas = {"Maria", "Claudia", "Josefina", "Paola", "Linda"};
const array<char[10], N_APEL> apel = {"Torres", "Flores", "Campos", "Acosta", "Aguirre", "Molina", "Silva", "Rojas", "Rios", "Castillo"};

struct {
   char id;
   char nombre[20];
} const Carrera[N_CAR] = {{'B', "Bachillerato"},{'I', "Ingenieria"},{'M', "Magister"}};

struct Alum{
	int id;		// cree un entero alearotio positivo
	char nombres[21];	// 2 nombres (separados por un espacio en blanco), 
	char apellidos[21];	// 2 apellidos provenientes de apel (separados por un espacio en blanco)
	bool masc;		// true: masculino, false: femenino
	char idCarrera; 	// 'B', 'I' o 'M'
	int edad;		// IN [MIN_EDAD..MAX_EDAD]
};

void genAlumnos(vector<Alum> &Alumnos);
void print_alumnos(vector<Alum> &Alumnos);
void quickSortId(vector<Alum> &Alumnos, const int l, const int r);
int partitionId(vector<Alum> &Alumnos, const int l ,const int r);
int median_aprox(vector<Alum> &Alumnos, const int l, int r);
int binarySearchId(vector<Alum> &Alumnos, const int x);
void insertionSortNombre(vector<Alum> &Alumnos);
int binarySearchNombre(vector<Alum> &Alumnos, const string s);

// A esta definición del main(), se le pueden pasar argumentos
int main(int argc, char **argv) {
	if(argc != 2){
		printf("Error. Debe ejecutarse como ./alum n\n");
		exit(EXIT_FAILURE);
	}

    const int n = atoi(argv[1]);
	vector<Alum> Alumnos(n);	// ESTO ES MEMORIA DINAMICA --> no sabe el compilador cuantos bytes son

	genAlumnos(Alumnos);
    printf("Arreglo inicial:\n");
	print_alumnos(Alumnos);
    printf("\nOrdenando arreglo por id\n");
    quickSortId(Alumnos, 0, n-1);
    printf("arreglo ordenado!, imprimiendo arreglo:\n");
    print_alumnos(Alumnos);

    const int x = rand();
    printf("\nbuscando id: %d\n", x);
    int pos = binarySearchId(Alumnos, x);
    if (pos == -1)
        printf("id no encontrado!\n");
    else{
        printf("la id fue encontrada en la posicion: %d\n", pos);
    }

    printf("\nOrdenando arreglo por nombre\n");
    insertionSortNombre(Alumnos);
    printf("arreglo ordenado!, imprimiendo arreglo:\n");
    print_alumnos(Alumnos);

    string s;
    if(rand()%2 == 0){
			s = string(ellas.at(rand()%8));
			s += " ";
			s += ellas.at(rand()%8);
	}else{
			s = string(ellos.at(rand()%8));
			s += " ";
			s += ellos.at(rand()%8);
	}
    printf("\nbuscando nombre: %s\n", s.c_str());
    pos = binarySearchNombre(Alumnos, s);
    if (pos == -1)
        printf("\nid no encontrado!\n");
    else{
        printf("la id fue encontrada en la posicion: %d\n", pos);
    }

	return EXIT_SUCCESS;
}

// generar n alumnos con dos nombres y 2 apellidos aleatorios desde los arreglos globales
void genAlumnos(vector<Alum> &Alumnos) {
	int i, a, b;

	for(i=0; i < (int)Alumnos.size(); ++i){
		Alumnos.at(i).id = rand();
		strcpy(Alumnos.at(i).apellidos, apel.at(rand()%N_APEL)); // primer apellido
		strcat(Alumnos.at(i).apellidos, " ");
		strcat(Alumnos.at(i).apellidos, apel.at(rand()%N_APEL));

        a = b = rand()%N_NOM;
            while (a == b)
				b = rand()%N_NOM;
		
		if(rand()%2 == 0){
			Alumnos.at(i).masc = false;
            
			strcpy(Alumnos.at(i).nombres, ellas.at(a));
			strcat(Alumnos.at(i).nombres, " ");
			strcat(Alumnos.at(i).nombres, ellas.at(b));
		}else{
			Alumnos.at(i).masc = true;
            
			strcpy(Alumnos.at(i).nombres, ellos.at(a));
			strcat(Alumnos.at(i).nombres, " ");
			strcat(Alumnos.at(i).nombres, ellos.at(b));
		}

		Alumnos.at(i).edad = MIN_EDAD + rand()%(MAX_EDAD-MIN_EDAD+1);
		Alumnos.at(i).idCarrera = Carrera[rand()%N_CAR].id;
	}
}

void print_alumnos(vector<Alum> &Alumnos) {
	for (Alum &alumno : Alumnos){
		printf("Id        : %d\n", alumno.id);

		if (alumno.masc)
			printf("Sexo      : Masculino \n");
		else
			printf("Sexo      : Femenino \n");

		printf("Nombres   : %s\n", alumno.nombres);
		printf("Apellidos : %s\n", alumno.apellidos);
		printf("Carreara  : ");
		switch (alumno.idCarrera) {
			case 'B':
				printf("%s\n",Carrera[0].nombre);
				break;
			case 'I':
				printf("%s\n",Carrera[1].nombre);
				break;
			case 'M':
				printf("%s\n",Carrera[2].nombre);
				break;
			default:
				printf(" NO DEFINIDA !! \n");
				break;
		}
		printf("Edad      : %d\n\n", alumno.edad);
	}
}

void quickSortId(vector<Alum> &Alumnos, const int l, const int r) {
    if(l>=r)
        return;
    
    int p = partitionId(Alumnos, l, r);
    quickSortId(Alumnos, p+1, r);
    quickSortId(Alumnos, l, p-1);
}

int partitionId(vector<Alum> &Alumnos, const int l ,const int r) {
    const int pivot = median_aprox(Alumnos, l, r);
    //toma la posiccion a la derecha del pivote
    //que inicia en el mayor indice del intervalo
    int rp= r+1;

    for(int j=r; j>l; --j){
        //si el valor de la posicion actual es mayor al pivote, la rp se mueve un espacio a la izquierda
        // (pues ahora hay un elemento mas que queda a la derecha del pivote)
        if(Alumnos.at(j).id > pivot){
            --rp;
            swap(Alumnos.at(rp), Alumnos.at(j));
        }
    }
    //dejamos el pivote en la posicion correcta
    swap(Alumnos.at(rp-1), Alumnos.at(l));
    return rp-1;
}

//calcula la mediana aproximada del intervalo
int median_aprox(vector<Alum> &Alumnos, const int l, int r) {
    int m = l + (r-l)/2;
    Alum tmp;

    //Calculamos la media aproximada que vimos en ejercicios previos
    if (Alumnos.at(l).id <= Alumnos.at(m).id){
        if (Alumnos.at(r).id <= Alumnos.at(l).id) return Alumnos.at(l).id;  /* r l m */
        if (Alumnos.at(m).id <= Alumnos.at(r).id) r = m;                    /* l m r */
                                                                            /* l r m */
    } else{
        if (Alumnos.at(l).id <= Alumnos.at(r).id) return Alumnos.at(l).id;  /* m l r */
        if (Alumnos.at(r).id <= Alumnos.at(m).id) r = m;                    /* r m l */
                                                                            /* m r l */
    }

    //colocamos el pivote al inicio del intervalo en preparacion para la particion
    tmp = Alumnos.at(r);
    Alumnos.at(r) = Alumnos.at(l);
    Alumnos.at(l) = tmp;
    //por el paso anterior el valor de la media es la id de Alumnos.at(l)
    return Alumnos.at(l).id;
}

int binarySearchId(vector<Alum> &Alumnos, const int x) {
    int l = 0, r = (int)Alumnos.size()-1;

    while (l <= r) {
        int m = l + (r-l)/2;

        if (Alumnos.at(m).id == x)
            return m;

        //si x es mayor, ignoramos la mitad izquierda
        if (Alumnos.at(m).id < x)
            l = m+1;
        //si x es menor, ignoramos la mitad derecha
        else
            r = m-1;
    }

    //retornamos -1 si no se encontro
    return -1;
}

void insertionSortNombre(vector<Alum> &Alumnos) {
    int j;
    Alum key;
    
    for (int i=1; i < (int)Alumnos.size(); ++i) {
        key = Alumnos.at(i);
        j = i-1;

        while (j>=0 && string(Alumnos.at(j).nombres) > string(key.nombres)) {
            Alumnos.at(j+1) = Alumnos.at(j);
            j = j-1;
        }
        Alumnos.at(j+1) = key;
    }
}

int binarySearchNombre(vector<Alum> &Alumnos, const string s) {
    int l = 0, r = (int)Alumnos.size()-1;

    while (l<=r) {
        int m = l + (r-l)/2;

        if (string(Alumnos.at(m).nombres) == s)
            return m;

        if (s > string(Alumnos.at(m).nombres))
            l = m+1;
        else
            r = m-1;
    }

    return -1;
}