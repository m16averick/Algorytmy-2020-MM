#include <iostream>

using namespace std;

struct node  
{ 

	int key;
	node* left;
	node* right;
	
	node(int k, node* l=nullptr, node* r=nullptr)
		:key(k), left(l), right(r)
	{}
};


void insert(node *& t, int x) 
{
	node **t1=&t;
	while(*t1)
	{
		if(x<(*t1)->key)
			t1=&((*t1)->left);
		else
			t1=&((*t1)->right);
	}
	*t1=new node(x);
}  



node* find(node* t,int x) 
{
	while(t && t->key!=x)
	{
		if(x<t->key) 
			t=t->left; 
		else
			t=t->right; 
	}
	return t;
}

int main()
{
	node* t=nullptr; 
	
    
	insert(t,1);
	insert(t,2);
	insert(t,3);
    cout << find(t, 2) << endl;

    cout << "elo";

    return 0;
}