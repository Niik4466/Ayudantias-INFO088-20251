#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

struct Sequence
{
	char *seq; 	//una combinacion de m letras del diccionario DNA
	struct Sequence *next;
};
typedef struct Sequence ADNSEQ;

#define N_SEQ 4
char DNA[] = "ACGT";
char MOTIF[] = "AG"; // "AG" o "GA" es el motif a buscar en cada secuencia para determinar su key en T

int insertInT(ADNSEQ **T, int m, char *st);
void printT(ADNSEQ **T, int m);

int main(int argc, char **argv)
{
	int i, j;
	if(argc != 3)
	{
		cout << "Error. Debe ejecutarse como ./problemaB2 n m" << endl;
		exit(EXIT_FAILURE);
	}
	int n = atoi(argv[1]);
	int m = atoi(argv[2]);

	ADNSEQ **T = new ADNSEQ*[m];
	for(i=0;i<m;i++)
	{
		ADNSEQ T[i] = {};
	}

	int num;
	for(i=0;i<n;i++)
	{
		char *s = new char[m];
		for(j=0;j<m;j++)
		{
			num = rand()%4;
			s[j] = DNA[num];
		}
		insertInT(T, m, s);
	}
	printT(T,m);
	

	cout << "Fin Problema B2" << endl;

	return EXIT_SUCCESS;
}

//Inserta s y retorna su clave en T
int insertInT(ADNSEQ **T, int m, char *s)
{
	int key=0;

	for(int i=0;i<m;i++)
	{
		if((s[i]=='A' && s[i+1]=='G') || (s[i]=='G' && s[i+1]=='A'))
			key++;
	}
	ADNSEQ *p = new ADNSEQ;
	p->seq = s;
	
	p->next = T[key];
	T[key] = p;

	return key;
}

void printT(ADNSEQ **T, int m)
{
	int i;
	ADNSEQ *p;

	cout << "Tabla T... " << endl;
	for(i=0; i<m; i++)
	{
		cout << "T[" << i << "]:";
		if (T[i] != nullptr)
		{
			p = T[i];
			while (p!=nullptr)
			{
				cout << p->seq << " ";
				p = p->next;
			}
		}
		cout << endl;
	}
}