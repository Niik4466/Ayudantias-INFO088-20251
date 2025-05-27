/* Ejercicio 2
 * 
 *  Realizar funcion que swapee 2 elementos
 *  deben de declararla
 *
*/

#include <iostream>
#include <vector>

#define TEST 0

void badPractice(std::vector<int> Vec);
void goodPractice(std::vector<int> &Vec);

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
  std::cout << "Variable i \t" << i << "\t\t referencia a la variable i " << &i << std::endl;
  std::cout << "Puntero ptr \t" << ptr << "\t valor al que apunta el puntero ptr " << *ptr << std::endl;
  std::cout << "Referencia ref \t" << ref << "\t\t referencia de la referencia ref " << &ref << std::endl;

  if (TEST == 1){
    std::vector<int> vec(1048576, 0);
    badPractice(vec);
  }

  // Aqui escriban su main

  return 0;
}

void badPractice(std::vector<int> Vec){
  return; // No hace nada, pero es un ejemplo de mala practica
}

void goodPractice(std::vector<int> &Vec){
  return; // No hace nada, pero es un ejemplo de buena practica
}
