/*
Nota. Algunas funciones en string que son muy útiles:
        strcpy(a, b);
        copia el contenido del string 'b' a la variable string 'a'
También se puede usar como:
        strcpy(a, "Nuevo valor");

Además con:
        strcat(a, b);  , o con: 
        strcat(a, "se aniade al final");
        el contenido del segundo argumento se aniade al final de la variable string 'a'
*/

/*
Ejercicio 1:
Teniendo un arreglo de Alum[0..n-1] llamado "Alumnos", cree la función quickSortId(vector<Alum> &Alumnos, const int l, const int r)
que ordena el arreglo de alumnos ascendentemente utilizando el campo id.
Luego de ordenar el arreglo, intente buscar una id aleatoria utilizando binarySearchId(vector<Alum> &Alumnos, const int x).

Ejercicio 2:
Siguiendo el enunciado del ejercicio anterior, cree la función insertionSortNombre(vector<Alum> &Alumnos)
¿De que manera puede ordenarse según el nombre, considerando que son caracteres y un nombre puede ser igual a otro?
Adicionalmente implemente un binarySearchNombre(vector<Alum> &Alumnos, const char c[21]) el cual, despues de ordenarlo con su insertionSort,
busque un nombre en el arreglo.
*/

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
int binarySearchId(vector<Alum> &Alumnos, const int x);
void insertionSortNombre(vector<Alum> &Alumnos);
int binarySearchNombre(vector<Alum> &Alumnos, const char c[21]);

// A esta definición del main(), se le pueden pasar argumentos
int main(int argc, char **argv) {
	if(argc != 2){
		fputs_unlocked("Error. Debe ejecutarse como ./alum n\n", stdout);
		exit(EXIT_FAILURE);
	}

    const int n=atoi(argv[1]);
	vector<Alum> Alumnos(n);	// ESTO ES MEMORIA DINAMICA --> no sabe el compilador cuantos bytes son

	genAlumnos(Alumnos);

	print_alumnos(Alumnos);

	return EXIT_SUCCESS;
}

// generar n alumnos con dos nombres y 2 apellidos aleatorios desde los arreglos globales
void genAlumnos(vector<Alum> &Alumnos) {
	int i, a, b;

	for(i=0; i<(int)Alumnos.size(); ++i){
		Alumnos.at(i).id = rand();
		strcpy(Alumnos.at(i).apellidos, apel.at(rand()%N_APEL)); // primer apellido
		strcat(Alumnos.at(i).apellidos, " ");
		strcat(Alumnos.at(i).apellidos, apel.at(rand()%N_APEL));

        a = b = rand()%N_NOM;
            while (a==b)
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
    printf("Lista de Alumnos:\n");
	for (Alum &alumno : Alumnos){
		printf("Id        : %d\n", alumno.id);

		if (alumno.masc)
			fputs_unlocked("Sexo      : Masculino \n", stdout);
		else
			fputs_unlocked("Sexo      : Femenino \n", stdout);

		printf("Nombres   : %s\n", alumno.nombres);
		printf("Apellidos : %s\n", alumno.apellidos);
		fputs_unlocked("Carreara  : ",stdout);
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
				fputs_unlocked(" NO DEFINIDA !! \n", stdout);
				break;
		}
		printf("Edad      : %d\n\n", alumno.edad);
	}
}

void quickSortId(vector<Alum> &Alumnos, const int l, const int r) {

}

int partitionId(vector<Alum> &Alumnos, const int l ,const int r) {
    return 0;
}

int binarySearchId(vector<Alum> &Alumnos, const int x) {
    return 0;
}

void insertionSortNombre(vector<Alum> &Alumnos) {

}

int binarySearchNombre(vector<Alum> &Alumnos, const char c[21]) {
    return 0;
}
