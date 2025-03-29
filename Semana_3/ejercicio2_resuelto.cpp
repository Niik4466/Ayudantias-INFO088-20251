#include <iostream>
#include <vector>
using namespace std;

#define TEST 0

void badPractice(vector<int> Vec);
void goodPractice(vector<int> &Vec);

// Declaracion de la funcion intercambiar utilizando punteros
void intercambiarConPunteros(int* a, int* b);

// Declaracion de la funcion intercambiar utilizando referencias
void intercambiarConReferencias(int& a, int &b);

int main(){
  int i = 4;            // Declaracion de una variable de tipo int + instruccion de asignacion
  int* ptr;             // Declaracion de un puntero a un int
  int& ref = i;         // Declaracion de una referencia + instruccion de asignacion
  // Notar que los simbolos * y & en declaraciones, funcionan como declaradores, es decir.
    // * Declara un puntero
    // & Declara una referencia

  ptr = &i;     // Instruccion de asignacion
  // Notar que los simbolos & y * en una Instruccion Funciona como un operador
    // - * Obtiene el valor al que apunta un puntero
    // - & Obitene el valor por referencia de una variable (memory adress o puntero)


  // Como se ven estos valores?
  cout << "Variable i \t" << i << "\t\t referencia a la variable i " << &i << endl;
  cout << "Puntero ptr \t" << ptr << "\t valor al que apunta el puntero ptr " << *ptr << endl;
  cout << "Referencia ref \t" << ref << "\t\t referencia de la referencia ref " << &ref << endl;

  if (TEST == 1){
    vector<int> vec(1048576, 0);
    badPractice(vec);
  }

  cout << "####------------------------------------------####" << endl;

  int a = 5;
  int b = 0;

  cout << "Valores iniciales: " << endl << "a = " << a << endl << "b = " << b << endl << endl;

  intercambiarConPunteros(&a, &b);

  cout << "Valores luego de intercambiar con punteros " << endl << "a = " << a << endl << "b = " << b << endl << endl;

  intercambiarConReferencias(a, b);

  cout << "Valores luego de intercambiar con referencias " << endl << "a = " << a << endl << "b = " << b << endl;


  return 0;
}

// funcion intercambiar utilizando punteros
void intercambiarConPunteros(int* a, int* b){
  // Guardamos el elemento apuntado por a en la variable temp
  int temp = *a;
  // Hacemos que el elemento apuntado por a, ahora sea el elemento apuntado por b
  *a = *b;
  // Hacemos que el elemento apuntado por b, ahora sea el elemento almacenado por la variable temp
  *b = temp;
}

// funcion intercambiar utilizando referencias
void intercambiarConReferencias(int& a, int &b){
  int temp = a;
  a = b;
  b = temp;
}

void badPractice(vector<int> Vec){
  badPractice(Vec);
}

void goodPractice(vector<int> &Vec){
  goodPractice(Vec);
}
