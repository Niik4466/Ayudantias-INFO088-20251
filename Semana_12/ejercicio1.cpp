/*
    Problema: Se tiene una maleta que soporta 100 de peso, la cual se quiere llenar con objetos que tienen un peso determinado. 
    Se desea maximizar la cantidad de objetos en la maleta, sin exceder el peso máximo permitido.

    La mochila se representa por la siguiente estructura:
    
    struct Mochila {
        int pesoMaximo;
        vector<int> objetos;
    };

    Donde vector<int> objetos representa los pesos de los objetos agregados a la mochila.

    Solucion: Se debe utilizar un algoritmo para seleccionar los objetos que se pueden agregar a la mochila
    Esto se realizará utilizando una cola de prioridad para seleccionar los objetos con menor peso primero.
    Usted deberá completar las funciones:
        
    - llenarMochila(Mochila& mochila, priority_queue<int, vector<int>, greater<int>>& objetos);
        Se debe llenar la mochila con los objetos de menor peso hasta que no se pueda agregar más sin exceder el peso máximo.
    - crearColaDePrioridad(const vector<int>& pesos);
        Crea una cola de prioridad a partir de un vector de pesos, ordenando los objetos de menor a mayor peso.
    - crearObjetos(vector<int>& objetos, int n);
        Crea un vector de objetos con pesos aleatorios entre 1 y 50, donde n es la cantidad de objetos a crear.

    y el main para probar su funcionamiento.
    - Se debe llamar a las funciones codificadas
    - Se debe imprimir los objetos antes de llenar la mochila.
    - Se debe imprimir el contenido de la mochila al final del programa.
     
*/

#include <iostream>
#include <vector>
#include <queue> 

struct Mochila
{
    int pesoMaximo;
    std::vector<int> objetos;
};

void llenarMochila(Mochila& mochila, std::priority_queue<int, std::vector<int>, std::greater<int>>& objetos);

std::priority_queue<int, std::vector<int>, std::greater<int>> crearColaDePrioridad(const std::vector<int>& pesos);

std::vector<int> crearObjetos(std::vector<int>& objetos, int n);

int main(int argc, char** argv){
    
}