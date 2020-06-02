int poziom(node * t, int klucz)
{
	int poziom = 1;

	//sprawdzam dopoki da sie isc w dol
	while(t->left || t->right)
	{
		//jesli element drzewa jest kluczem koncze petle
		if (t->x == klucz)
			break;

		//jesli nie to ide w ,,jego strone"
		if(klucz < t->x) 
			t= t -> left; 
		else
			t= t -> right; 
		//i zwiekszam poziom na ktorym bedzie
		poziom++;
	}
	//jesli nie ma go na ostatnim poziomie znaczy ze nie wystepuje w drzewie 
	if (t->x != klucz)
		return 0;
	
	return poziom;

	//0 brak, 1 w korzeniu, 2 w dziecku korzenia itd..
}