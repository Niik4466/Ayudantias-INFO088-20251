#include <cstdlib>
#include <cstdio> //<------- de aqui viene printf y scanf
#include <string>

bool isBiggerThanWord(std::string palabra1, std::string palabra2);

int main(int argc, char** argv){
    if (argc != 3){
        printf("Error, se debe ejecutar como ./prog \"palabra 1\" \"palabra 2\"\n");
        exit(EXIT_FAILURE);
    }

    // Obtenemos las palabras dadas como argumento al ejecutar ./prog "palabra1" "palabra2"
    //                                                            0       1          2
    char* palabra1 = argv[1];
    char* palabra2 = argv[2];

    isBiggerThanWord(palabra1, palabra2) ?
        printf("%s es mas grande que %s\n", palabra1, palabra2) : printf("%s es igual o mas pequeño que %s\n", palabra1, palabra2);

    return EXIT_SUCCESS;
}

bool isBiggerThanWord(std::string palabra1, std::string palabra2){
    // Casos de borde

    // Si palabra1 es nula o no tiene nada (no hay palabra) entonces nada puede ser mayor estricto que ella y por ende se retorna false
    if (palabra1.empty()) return false;
    // Si palabra2 es nula o no tiene nada (no hay palabra) entonces automaticamente palabra1 es mas grande puesto que no es nula.
    if (palabra2.empty()) return true;

    int i1=0; //<----- Itera sobre la palabra1
    int i2=0; //<----- Itera sobre la palabra2

    // Si ninguna de las dos palabras llega a su final. Seguimos iterando.
    while (palabra1[i1] != '\0' && palabra2[i2] != '\0'){

        // Si el caracter de la palabra1 en el lugar i1 es mas grande que el caracter de la palabra2 en el lugar i2
        // entonces palabra1 es mas grande y retornamos true, si no seguimos iterando.
        if (palabra1[i1] > palabra2[i2])
            return true;
        
        ++i1;
        ++i2;
    }

    if (palabra1[i1] == '\0')
        return false;

    return true;
}
