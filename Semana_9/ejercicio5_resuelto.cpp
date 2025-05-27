#include <ios>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

struct actividad{
    uint id;
    short int hora_ini;
    short int min_ini;
    short int hora_fin;
    short int min_fin;
};

void llenaActividades(vector<actividad> &actividades);
void printAct(vector<actividad> &actividades);
void ordenaAct(vector<actividad> &actividades, uint l, uint r);
uint llenaStackAct(vector<actividad> actividades, stack<actividad> &planificacion);

void llenaActividadesAleatorio(vector<actividad> &actividades, uint n);

int main() {
    vector<actividad> actividades(10);
    llenaActividades(actividades);
    printAct(actividades);

    printf("Ordenando actividades...\n");
    ordenaAct(actividades, 0, static_cast<uint>(actividades.size()-1));
    printAct(actividades);

    stack<actividad> planificacion;
    printf("John podra asistir a %i actividades\n", llenaStackAct(actividades, planificacion));
    while(!planificacion.empty()) {
        actividad temp = planificacion.top();
        planificacion.pop();
        printf("\nActividad: %i,\thora de inicio: %i:%i,\thora de finalización: %i:%i\n", 
                temp.id, temp.hora_ini, temp.min_ini, temp.hora_fin, temp.min_fin);
    } 
    printf("\n");

    return EXIT_SUCCESS;
}

int partition(vector<actividad> &actividades, uint l, uint r)
{
	int p = l;
    actividad pv = actividades.at(p);

	for(uint i=l+1;i<=r;++i)
	{
		if(actividades.at(i).hora_fin == pv.hora_fin ? actividades.at(i).min_fin < pv.min_fin : actividades.at(i).hora_fin < pv.hora_fin) //cambiamos la condicion de comparacion
		{
			p++;
			swap(actividades.at(i),actividades.at(p));
		}
	}
	swap(actividades.at(l),actividades.at(p));
	return p;
}

void ordenaAct(vector<actividad> &actividades, uint l, uint r) {
    if(l<r)
	{
		int p = partition(actividades , l, r);
		ordenaAct(actividades, l, p-1);
		ordenaAct(actividades, p+1, r);
	}
}

void ordenaActLambda(vector<actividad> &actividades) { //Variacion usando sort de la stl y una funcion lambda para definir la condicion de ordenamiento
    sort(actividades.begin(), actividades.end(), [](actividad a, actividad b) -> bool {
            return (a.hora_fin == b.hora_fin ? a.min_fin < b.min_fin : a.hora_fin < b.hora_fin);
        });
}

uint llenaStackAct(vector<actividad> actividades, stack<actividad> &planificacion) {
    uint n = static_cast<uint>(actividades.size())-1;
    planificacion.push(actividades.at(0));
    for(uint i=1;i<=n;++i)
        if(actividades.at(i).hora_ini == planificacion.top().hora_fin ? actividades.at(i).min_ini > planificacion.top().min_fin : actividades.at(i).hora_ini > planificacion.top().hora_fin)
            planificacion.push(actividades.at(i));
    
    return static_cast<uint>(planificacion.size());
}

void llenaActividades(vector<actividad> &actividades) {
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

void printAct(vector<actividad> &actividades) {
    for (actividad act : actividades) {
        printf("\nActividad: %i,\thora de inicio: %i:%i,\thora de finalización: %i:%i\n", 
                act.id, act.hora_ini, act.min_ini, act.hora_fin, act.min_fin);
    }
    printf("\n");
}

void llenaActividadesAleatorio(vector<actividad> &actividades, uint n) {
    actividad rand_act;
    for(uint i=0;i<n;++i) {
        do{
            rand_act = {static_cast<uint>(i+1), static_cast<short int>(rand()%25), static_cast<short int>(rand()%60), static_cast<short int>(rand()%25), static_cast<short int>(rand()%60)};
        }while(rand_act.hora_fin == rand_act.hora_ini ? rand_act.min_fin > rand_act.min_ini : rand_act.hora_fin > rand_act.hora_ini);
        actividades.at(i) = rand_act;
    }
}