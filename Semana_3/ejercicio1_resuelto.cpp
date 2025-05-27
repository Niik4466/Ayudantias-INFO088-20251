#define N 30

int main(){

  // Creacion de arreglo estatico
  int estatico[20] = {0};
 
  // Creacion de arreglo dinamico
  int* dinamico = new int[20];

  // Cual es la utilidad del arreglo Estatico?Construcción de la Estructura + Experimentos
  //  Es mas veloz acceder a elementos del arreglo, dado que obtiene memoria desde el stack de memoria

  // Cual es la utilidad del arreglo Dinamico?
  //  Es posible cambiar el tamanio del arreglo dentro de la ejecucion de nuestro programa
  //  Por ejemplo:

  dinamico = new int[30];
  // o con:
  for (int i = 0; i < N; ++i){
    dinamico = new int[i];
  }

  return 0;
}
