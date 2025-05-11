/*
Se tiene el siguiente problema:
Estamos en semana de aniversario y la universidad nos presenta una serie de actividades para participar
John es un alumno y como sólo tiene un día libre quiere participar en la mayor cantidad de actividades posibles,
sin embargo no sabe como realizar una planificación acorde para participar en todas ellas, 
así que le pide ayuda a sus amigos informáticos.

Para cada actividad se tiene un id de la actividad, una hora de inicio y una hora de fin en formato hh:mm

Con esta información a los informáticos se les ocurre lo siguiente:
Crearon una struct llamada "actividad" la cual almacena la información de una actividad,
con esa struct generaron un vector que almacena los datos de todas las actividades a las que John podria inscribirse,
luego con la información recopilada, van a ordenar el arreglo de manera acendente considerando la hora de 
finalización de cada actividad con la función "void ordenaAct(vector<actividad> &actividades)"
la cual toma como argumento el arreglo de actividad.
Una vez tienen el arreglo ordenado van a utilizar una pila llamada "planificación" para guardar las actividades que deberá realizar John,
que llenarán con la función "int llenaStackAct(vector<actividad> &actividades, stack<actividad> &planificacion)"
la cual agrega una actividad al stack si la actividad no tiene topes de horario con otras actividades.
Además retorna la cantidad de actividades que puede realizar John.

Sin embargo como sus amigos informáticos no tenían tiempo para llenar estas funciones le pidieron a los estudiantes
del ramo INFO088 que crearan las funciones y probarán que sean correctas.


RETO: pueden llenar la función llenaActividadesAleatorio la cual hace lo mismo que llenaActividadesEstatico
      pero de manera aleatoria. (se randomiza la hora de inicio y hora de fin)


PD: Pueden modificar las funciones a su gusto, por ejemplo si quieren utilizar arreglos :D

*/
#include <ios>
#include <vector>
#include <stack>

struct actividad{
    int id;
    short int hora_ini;
    short int min_ini;
    short int hora_fin;
    short int min_fin;
};

void llenaActividades(std::vector<actividad> &actividades);
void printAct(std::vector<actividad> &actividades);
void ordenaAct(std::vector<actividad> &actividades);
short int llenaStackAct(std::vector<actividad> actividades, std::stack<actividad> &planificacion);

void llenaActividadesAleatorio(std::vector<actividad> &actividades);

int main() {
    std::vector<actividad> actividades(10);
    llenaActividades(actividades);

    printAct(actividades);


    return EXIT_SUCCESS;
}

void ordenaAct(std::vector<actividad> &actividades) {
    return;
}

short int llenaStackAct(std::vector<actividad> actividades, std::stack<actividad> &planificacion) {
    return 1;
}

void llenaActividades(std::vector<actividad> &actividades) {
    actividades.at(0) = {1, 9, 0, 10, 30};
    actividades.at(1) = {2, 10, 45, 12, 0};
    actividades.at(2) = {3, 13, 15, 14, 0};
    actividades.at(3) = {4, 14, 30, 15, 45};
    actividades.at(4) = {5, 16, 0, 17, 30};
    actividades.at(5) = {6, 8, 30, 9, 45};
    actividades.at(6) = {7, 11, 0, 12, 15};
    actividades.at(7) = {8, 15, 0, 16, 30};
    actividades.at(8) = {9, 17, 0, 18, 0};
    actividades.at(9) = {10, 19, 0, 20, 30};
}

void printAct(std::vector<actividad> &actividades) {
    for (actividad act : actividades) {
        printf("\nActividad: %i,\thora de inicio: %i:%i,\thora de finalización: %i:%i\n", 
                act.id, act.hora_ini, act.min_ini, act.hora_fin, act.min_fin);
    }
    printf("\n");
}
