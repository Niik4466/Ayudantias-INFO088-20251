/* 
* Para este problema tendran que implementar un algoritmo de ordenamiento
* para ordenar una matriz (arreglos bidimensionales), y luego implementar una variacion de binarySearch
* que funcione en matrices para buscar un elemento generado de forma aleatorea.
 */
#include <cstdio>
#include <vector>
#include <random>

#define MAX 1000

void imprimeMatriz(std::vector<std::vector<int>> &matrix);
int matrixBinarySearch(std::vector<std::vector<int>> &matrix, int x);

int main(int argc, char **argv) {
	if(argc!=2) {
		printf("Cantidad de argumentos invalida, se debe ejecutar el programa de la manera \n%s <tamaño_matriz>", argv[0]);
		return 1;
	}
	int n = atoi(argv[1]);

	std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			matrix[i][j] = rand()%MAX;
		}
	}
	imprimeMatriz(matrix);

	int x = rand()%MAX;

	//En esta linea deben implementar el algoritmo de ordenamiento
	int answer = matrixBinarySearch(matrix, x);
	if(answer == -1)
		printf("El numero %d no fue encontrado\n", x);
	else
		printf("El numero %d fue encontrado en la posicion: %d\n", x, answer);
}

int matrixBinarySearch(std::vector<std::vector<int>> &matrix, int x) {
	return -1;
}

void imprimeMatriz(std::vector<std::vector<int>> &matrix) {
	int n = static_cast<int>(matrix.size());
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}
