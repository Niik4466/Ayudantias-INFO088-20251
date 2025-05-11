#include <string>

struct nodeList {
    char val;
    nodeList* prev;
    nodeList* next;
};
typedef struct nodeList nodo;

void appendToListL(nodo **l, char letra);
void imprimeLista(nodo *l);
bool esPalindrome(nodo *l, nodo *fl, int n);

int main(int argc, char** argv){
    if (argc < 1){
        printf("Debe ejecutarse como ./prog palabra n !!\n");
        return EXIT_FAILURE;
    }

    std::string palabra = argv[1];
    nodo *list = nullptr, *end_list;
    list = end_list = nullptr;
    //obtengo el largo del arreglo
    int n = (int)palabra.size();
    
    //llenamos nuestra lista dinámica
    for (int i = n-1; i>=0; --i) {
        appendToListL(&list, (palabra[i]));
        if(i == n-1) end_list = list;
    }
    
    imprimeLista(list);

    if (esPalindrome(list, end_list, n))
        printf("Es palindrome!!\n");
    else
        printf("No es palindrome :c\n");

    return EXIT_SUCCESS;

}

bool esPalindrome(nodo *l, nodo *fl, int n) {
    for(int i=0; i<n/2; ++i){
        if (l->val != fl->val) return false;
        l = l->next;
        fl = fl->prev;
    }

    return true;
}

void appendToListL(nodo **l, char letra) {
    if(*l == nullptr) {
        *l = new nodo;
        (*l)->val = letra;
    }else {
        nodo *p = new nodo;
        p->next = *l;
        (*l)->prev = p;
        p->val = letra;
        *l = p;
    }
}

void imprimeLista(nodo *l){
    while(l != nullptr){
        printf("%c ", l->val);
        l = l->next;
    }
    printf("\n");
}
