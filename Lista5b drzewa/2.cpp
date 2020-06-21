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




int find(node* tree,int x) 
{
	int level = 0;
	while(tree && tree->key!=x)
	{
		if(x<tree->key) 
			tree=tree->left; 
		else
			tree=tree->right; 
		level += 1;
	}
	return level;
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