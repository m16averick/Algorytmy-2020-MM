
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


int nty(int n, lnode *L)
{
	int counter = 0;
	
	return lnode.next;
	
}

int suma(lnode *L)
{
	int r = 0;
	while (true)
	{
		if (L == nullptr) break;
		r += L->key;
		
	}

	return r;

}

int main()
{
	lnode* l = nullptr;
	l = new lnode(3, l);
	l = new lnode(5, l);
	l = new lnode(8, l);
	//std::cout << suma(l);
	cout << nty(2, l);

}