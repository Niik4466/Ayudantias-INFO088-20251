#include "AVL.h"

AVL::AVL() {
	root = NULL;
}

AVL::~AVL() {
	destroyTree(&root);
}

void AVL::destroyTree(nodoAVL **t){
	if ((*t) == nullptr)
		return;

	nodoAVL *p = *t;
	destroyTree(&(p->izq));
	destroyTree(&(p->der));
	delete p;
	*t = NULL;
}

void AVL::printInorder(nodoAVL *t){
	if (t != nullptr){
		printInorder(t->izq);
		printf("%i ", t->key);	
		printInorder(t->der);
	}
}

// Imprime en preorder incluyendo la altura del nodo
void AVL::printPreorder(nodoAVL *t){
	if (t != nullptr){
		printf("%i(h:%i) ", t->key, t->height);
		printPreorder(t->izq);
		printPreorder(t->der);
	}
}


// retorna el maximo entre a y b
int maxVal(int a, int b) {
	return (a > b)? a : b;
}

// retorna la altura del nodo (si no es nulo la altura ya esta calculada)
int AVL::getHeight(nodoAVL *nod) {
	if (nod == nullptr)
		return -1;
	return nod->height;
}

// Obtiene el Factor de Equilibrio del nodo nod
int AVL::getFE(nodoAVL *q){
	if (q == nullptr)
		return 0;
	return getHeight(q->der) - getHeight(q->izq);
}

bool AVL::insert(nodoAVL **t, int num){
	nodoAVL *p; 
	if (*t == nullptr){
		p = *t = new nodoAVL();	
		p->key = num;
		p->height = 0;
		p->izq = p->der = NULL;
		
		return true;
	}
	
	p = *t;
	if (num < p->key){
		if(insert( &(p->izq) , num) == false)
			return false;
	}else{
		if (num > p->key){
			if(insert( &(p->der) , num) == false)
				return false;
		}else
			return false;
	}
	
	// NODO INSERTADO CORRECTAMENTE !!
	p->height = maxVal(getHeight(p->izq), getHeight(p->der)) + 1;
	int fEQ = getFE(p);
	if(fEQ < -1){
		// DESEQUILIBRIO POR LA IZQUIERDA
		if(num < p->izq->key){
			// CASO II
			*t = rightRotation(p);
		}else{
			// CASO ID
			p->izq = leftRotation(p->izq); 
			*t = rightRotation(p);
		}
	}else{
		if(fEQ > 1){
			// DESEQUILIBRIO POR LA DERECHA
			if(num > p->der->key){
				// CASO DD
				*t = leftRotation(p);
			}else{
				// CASO DI
				p->der = rightRotation(p->der); 
				*t = leftRotation(p);
			}
		}
	}
	
	return true;
}

// Rotacion a la izquierda en el nodo x (ver slide AVL Rotación Simple)
// se debe retornar y (nueva raíz de este subárbol)
nodoAVL* AVL::leftRotation(nodoAVL* x){
	nodoAVL* y = x->der;
	nodoAVL* T2 = y->izq;
	
	x->der = T2;
	y->izq = x;

	x->height = maxVal(getHeight(x->izq), getHeight(x->der)) + 1;
	y->height = maxVal(getHeight(y->izq), getHeight(y->der)) + 1;
	
	return y;
}

// Rotacion a la derecha en el nodo y. Retornamos el nodo raíz después de rotar
nodoAVL* AVL::rightRotation(nodoAVL* y){
	nodoAVL* x = y->izq;
	nodoAVL* T2 = x->der;
	
	y->izq = T2;
	x->der = y;

	y->height = maxVal(getHeight(y->izq), getHeight(y->der)) + 1;
	x->height = maxVal(getHeight(x->izq), getHeight(x->der)) + 1;

	return x;
}

bool AVL::remove(nodoAVL **t, int num){
	if(*t == nullptr)
		return false;

	nodoAVL *p = *t;
	if(p->key == num){
		if(p->izq == nullptr){
			*t = p->der;
			delete p;
		}else{
			if(p->der == nullptr){
				*t = p->izq;
				delete p;
			}else{
				nodoAVL *q = getLowest(p->der);
				p->key = q->key;
				remove(&(p->der), q->key);	
			}			
		}		
		if (*t == nullptr)
			return true;
	}else{
		bool elimina;
	
		if(num < p->key)
			elimina = remove(&(p->izq), num);
		else
			elimina = remove(&(p->der), num);

		if (elimina == false)
			return false;
	}
	
	p = *t;
	// NODO ELIMINADO CORRECTAMENTE !!
	p->height = maxVal(getHeight(p->izq), getHeight(p->der)) + 1;
	int fEQ = getFE(p);
	//cout << "getFE(p) " << fEQ << endl;
	if(fEQ < -1){
		// DESEQUILIBRIO POR LA IZQUIERDA
		if(getFE(p->izq) <= 0){
			// CASO II
			*t = rightRotation(p);
		}else{
			// CASO ID
			p->izq = leftRotation(p->izq); 
			*t = rightRotation(p);
		}
	}else{
		if(fEQ > 1){
			// DESEQUILIBRIO POR LA DERECHA
			if(getFE(p->der) >= 0){
				// CASO DD
				*t = leftRotation(p);
			}else{
				// CASO DI
				p->der = rightRotation(p->der); 
				*t = leftRotation(p);
			}
		}
	}

	return true;		
}

// retorna el menor nodo del arbol t (CONDICIÓN: t not NULL)
nodoAVL *AVL::getLowest(nodoAVL *t){
	if(t->izq != nullptr)
		return getLowest(t->izq);
		
	return t;
}

bool AVL::validaAVL(nodoAVL *t){
	if (t != nullptr){
		validaAVL(t->izq);
		validaAVL(t->der);		
	}
	
	if (getFE(t) < -1 || getFE(t) > 1){
		printf("ERROR. AVL desequilibrado en el nodo %i\n", t->key);
		exit(-1);
	}
	
	return true;
}
