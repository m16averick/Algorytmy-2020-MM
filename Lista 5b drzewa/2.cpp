#include <iostream>

using namespace std;

struct node  // drzewo bez wskaźnika na rodzica
{ 

	int key;
	node* left;
	node* right;
	
	node(int k, node* l=nullptr, node* r=nullptr)
		:key(k), left(l), right(r)
	{}
};




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

	node* tree2 = new node(7);
	node* tree = tree2;
	tree->left = new node(5);
	tree = tree->left;
	tree->left = new node(2);
	cout << find(tree2, 2);
	


    return 0;
}