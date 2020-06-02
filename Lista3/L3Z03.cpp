#include <iostream>

using namespace std;

struct lnode
{
	int key;
	lnode *next;

	lnode(int k, lnode* n) : key(k), next(n)
	{
        
	}

};

void show(lnode* L) 
{ 
    while (L != NULL) 
    { 
        cout << L->key << " "; 
        L = L->next; 
    } 

    cout << endl;
} 

void reverse(lnode*& L)
{

    lnode* l_operative = L->next;
    L->next = nullptr;

    while (l_operative !=nullptr)
    {
        lnode* temp = l_operative;
        l_operative = l_operative->next;
        show(L);
        show(temp);
        temp->next = L;
        L = temp;
    }

}


void insertion_sort(lnode *&L)
{
	//nowa lista ktora bedzie przechowywac posortowane elememnty
	lnode *sorted = nullptr;
	//aktualniy wezel
	lnode *current = L;

	while (current)
	{
		//nastepny element na kolejna iteracje
		lnode *next = current->next;

		//Właściwe wstawianie elementu 
		if (!sorted || sorted->key >= current->key)
		{
			current->next = sorted;
			sorted = current;
		}
		else
		{
			lnode *tmp = sorted;

			//dopoki jest jakis nastepny i jego wartosc jest mniejsza od nowej
			while (tmp->next && tmp->next->key < current->key)
				tmp = tmp->next;

			current->next = tmp->next;
			tmp->next = current;
		}

		current = next;
	}
	L = sorted;
}


int main()
{
    lnode* l = nullptr;
	l = new lnode(3, l);
	l = new lnode(8, l);
	l = new lnode(5, l);
	l = new lnode(2, l);
	l = new lnode(13, l);
    show(l);
    insertion_sort(l);
    show(l);
    return 0;
}
