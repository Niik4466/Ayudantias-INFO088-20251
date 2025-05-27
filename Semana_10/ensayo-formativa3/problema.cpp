#include "BST/BST_ADN.h"

#define LEN 4
char APHABET[] = {'A', 'C', 'G', 'T'};

int main(int argc, char **argv) {
	if(argc != 3) {
		std::cout << "Error. Debe ejecutarse como ./problema n k" << std::endl;
		exit(EXIT_FAILURE);
	}

	int n,k;
	n = atoi(argv[1]);
	k = atoi(argv[2]);

	
	
	std::cout << "### Fin Problema ###" << std::endl;
	return EXIT_SUCCESS;
}
