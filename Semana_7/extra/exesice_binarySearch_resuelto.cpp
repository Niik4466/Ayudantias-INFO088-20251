/* 
* Para este problema tendran que implementar un algoritmo de ordenamiento
* para ordenar una matriz (arreglos bidimensionales), y luego implementar una variacion de binarySearch
* que funcione en matrices para buscar un elemento generado de forma aleatorea.
*/

#include <algorithm>
#include <cstdio>
#include <vector>
#include <random>

#define MAX 1000

int matrixPartition(std::vector<std::vector<int>>& matrix, int l, int r);
void matrixQuickSort(std::vector<std::vector<int>>& matrix, int l, int r);
void imprimeMatriz(std::vector<std::vector<int>> &matrix);
void matrixInsertionSort(std::vector<std::vector<int>> &matrix);
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
	// matrixInsertionSort(matrix);
	matrixQuickSort(matrix, 0, n*n-1);

	printf("Matriz ordenada\n");

	imprimeMatriz(matrix);

	int answer = matrixBinarySearch(matrix, x);
	if(answer == -1)
		printf("El numero %d no fue encontrado\n", x);
	else
		printf("El numero %d fue encontrado en la posicion: %d\n", x, answer);
}

int matrixBinarySearch(std::vector<std::vector<int>> &matrix, int x) {
	int n = static_cast<int>(matrix.size());
	if (n == 0) return -1;
	int m = static_cast<int>(matrix[0].size());

	int left = 0;
	int right = n*m - 1;

	while (left <= right) {
		int mid = (right+left) / 2;
		int midValue = matrix[mid/m][mid%m];

		if (midValue == x) {
			return mid;
		}
		else if (midValue < x) {
			left = mid+1;
		}
		else {
			right = mid-1;
		}
	}
	return -1;
}

// Version 1
void ordena_matriz(std::vector<std::vector<int>> &matrix) {
	int n = static_cast<int>(matrix.size());
	if (n == 0) return;
	int m = static_cast<int>(matrix[0].size());
	int index = 0;

	std::vector<int> linealMatrix(n*m);

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			linealMatrix[index++] = matrix[i][j];
		}
	}

	for (int i = 1; i < n*m; ++i) {
		int key = linealMatrix[i];
		int j = i - 1;
		while (j > 0 && linealMatrix[j] > key) {
			linealMatrix[j + 1] = linealMatrix[j];
			j--;
		}
		linealMatrix[j + 1] = key;
	}

	index = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			matrix[i][j] = linealMatrix[index++];
		}
	}
}

// Version 2
void matrixInsertionSort(std::vector<std::vector<int>> &matrix){
	int n = static_cast<int>(matrix.size());
	if (n == 0) return;
	int m = static_cast<int>(matrix[0].size());

	for (int i = 1; i < n*m; ++i){
		int key = matrix[i/n][i%m];
		int j = i - 1;

		while (j >= 0 && matrix[j / m][j % m] > key) {
			matrix[(j + 1) / m][(j + 1) % m] = matrix[j / m][j % m];
			j--;
		}

		matrix[(j + 1) / m][(j + 1) % m] = key;
	}
}

//Version 3
void matrixQuickSort(std::vector<std::vector<int>>& matrix, int l, int r) { 
	if (l >= r) {
		return;
	}

	int pi = matrixPartition(matrix, l, r);
	matrixQuickSort(matrix, l, pi - 1);
	matrixQuickSort(matrix, pi + 1, r);
}

int matrixPartition(std::vector<std::vector<int>>& matrix, int l, int r) {
	int n = static_cast<int>(matrix.size());
	int pivot = matrix[l/n][l%n];  
	int l_bound = l;

	for (int j=l+1; j<=r; ++j) {
		if (matrix[j/n][j%n] < pivot) {
			++l_bound;
			std::swap(matrix[l_bound/n][l_bound%n], matrix[j/n][j%n]);
		}
	}
	std::swap(matrix[l/n][l%n], matrix[l_bound/n][l_bound%n]);
	return l_bound;
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
