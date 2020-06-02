#include <iostream>
#include <cassert>
using namespace std;
    // C. Juszczak (2019)

struct node  // drzewo bez wskaźnika na rodzica
{ 

	int x;
	node* left;
	node* right;
	
	node(int x0, node* l=nullptr, node* r=nullptr)
		:x(x0), left(l), right(r)
	{}
};


void insert(node *& t, int x) // wstawianie (nierekurencyjna)
{
	node **t1=&t;
	while(*t1)
		if(x<(*t1)->x)
			t1=&((*t1)->left);
		else
			t1=&((*t1)->right);
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






void remove(node *&t, int x)  // usuwanie elementu z drzewa (bez rekurencji)
{
	node **t1=&t;
	while (*t1 && (*t1)->x!=x)
	{
		if(x<(*t1)->x) 
			t1=&((*t1)->left); 
		else
			t1=&((*t1)->right); 
	}
	if(*t1)
	{
		if((*t1)->right && (*t1)->left)
		{
			node **t2=&((*t1)->right);
			while ((*t2)->left)
				t2=&((*t2)->left);
			(*t1)->x=(*t2)->x;
			t1=t2;
		}	
		if((*t1)->left==nullptr)
		{
			node *d=(*t1)->right;
			delete *t1;
			(*t1)=d;
		}
		else
		{
		    node *d=(*t1)->left;	
			delete *t1;
			(*t1)=d;
		}
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
	
	cout << find(t, 2);
    

}

