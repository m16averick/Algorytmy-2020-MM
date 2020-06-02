#include <iostream>
#include <cassert>
using namespace std;
    // C. Juszczak (2019)

struct node  // drzewo ze wskaźnikiemm na rodzica
{ 

	int x;
	node* left;
	node* right;
    node* parent;
	
	node(int x0, node* l=nullptr, node* r=nullptr)
		:x(x0), left(l), right(r)
	{}
};


void insert(node *& t, int x) // wstawianie (nierekurencyjna)
{
	node **t1=&t;
	while(*t1)
		if(x<(*t1)->x)
        {
            (*t1)->parent = *t1;
			t1=&((*t1)->left);
        }

		else
        {
            (*t1)->parent = *t1;
			t1=&((*t1)->right);
        }

	*t1=new node(x);
}  


node* find(node* t,int x)  // wyszukiwanie klucza (bez rekurencji)
{
	while(t && t->x!=x)
	{
		if(x<t->x) 
			t=t->left; 
		else
			t=t->right; 
	}
	return t;
}



void display(node *t,char z1=' ',char z2=' ') // in order z nawiasami 
{
	if(t)
	{
		std::cout<<z1;
		display(t->left,'(',')');
		std::cout<<t->x;
		display(t->right,'[',']');
		std::cout<<z2;
	}
}


int N(node* t) // ilość kluczy w drzewie (rekurenycjnie)
{
	if(!t) return 0;
	int nL=N(t->left);
	int nR=N(t->right);	 
	return nL+nR+1;
}


int H(node* t)  // wysokość drzwa BST (rekurencyjnie)
{
	if(!t) return 0;
	int hL=H(t->left);
	int hR=H(t->right);	 
	if(hR>hL)
		return 1+hR;
	else
		return 1+hL;
}



int min (node* t)  // minimalny klucz (bez rekurencji)
{
	assert(t);
	while(t->left)
		t=t->left;
	return t->x;
}



void remove(node *&t, int x)  // usuwanie elementu z drzewa (bez rekurencji)
{
	node **t1=&t;
    while ((*t1)->x != x)
    {
        if (x<(*t1)->x)    t1 = &(*t1)->left;
        else    t1 = &(*t1)->right;
    }
//brak dzieci

        if ( (*t1)->left == 0 && (*t1)->right == 0)
		{
			delete *t1;
			(*t1)=nullptr;
		}
//jedno dziecko
        else if ( (*t1)->right != 0 && (*t1)->left == 0 )
		{
			node *temp=(*t1)->right;
			delete *t1;
			(*t1)=temp;
		}

		else if ( (*t1)->left != 0 && (*t1)->right == 0 )
		{
			node *temp=(*t1)->left;
			delete *t1;
			(*t1)=temp;
		}
//dwoje dzieci
		else 
		{
			node *temp=(*t1)->right;
			int minimal = min(temp);
			remove(temp, minimal);
			delete *t1;
			(*t1)=temp;
		}
		
}





int main()
{
	node* t=nullptr; // tworzymy puste drzewo BST
	
	// dodajemy klucze

	insert(t,1);
	insert(t,2); 
	insert(t,3);
	insert(t,4);
	insert(t,5);
	insert(t,6);
	insert(t,7);

    remove(t, 3);
    remove(t, 7);

	insert(t, 3);
	remove(t,2);
	
	cout<<"struktura         :"; display(t);cout<<endl;
	cout<<"Ilość węzłow    = "<<N(t)<<endl;
	cout<<"Wysokość drzewa = "<<H(t)<<endl;
    

}

