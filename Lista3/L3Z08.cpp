struct BSTnode
{
	int x;
	BSTnode *left;
	BSTnode *right;

	//przechowuje liczbe prawych dzieci czyli wszystkich elementow wiekszych od niego
	//czyli najwiekszy element mial rightCount=0
	int rightCount;
    /*
    W rekurencyjnej funkcji insert należałoby przed przejsciem do prawej gałęzi zwiększyć rightCount aktualnego wezla
        idąc w lewo w aktualnym wezle nie zmienia sie nic a w nowo utwozonym licznik zaczyna od nowa
    */
};

BSTnode* ity(BSTnode *&t, int num)
{
	//zakladam ze indeksy szukanych beda od 1 (czyli jesli chcemy 1 to bedzie to najwiekszy element
	//jesli jest cos w korzeniu
	if (t)
	{
		BSTnode *tmp = new BSTnode;
		tmp = t;

		while (tmp)
		{
			if (tmp->rightCount + 1 == num)
				return tmp;
		
			//jesli szukany numer jest wiekszy to znacxy ze musimy isc ,,mniejsza" lewą gałęzią
			if (num > tmp->rightCount + 1)
			{
				//odejmuję liczbę prawych dzieci z aktalnego drzewa bo lewe dzieci maja rightCount liczone od 0
				//czyli np chce 8 element z kolei czyli jak w aktualnym jesy 5 to muszę dostać 3 z lewego
				num -= (tmp->rightCount + 1);
				//przechodze na lewo
				tmp = tmp->left;
			}
			else
				tmp = tmp->right;
		}
	}
}