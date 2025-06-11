// No acepta claves repetidas
bool BST::insert(nodoBST **t, int num)
{
	nodoBST *q;
	if (*t == nullptr)
	{
		*t = q = new nodoBST();
		q->key = num;
		q->izq = q->der = NULL;
		return true;
	}

	q = *t;
	if (num < q->key)
		return insert(&(q->izq), num);
		
	if (num > q->key)
		return insert(&(q->der), num);

	return false; // clave ya existe
}

