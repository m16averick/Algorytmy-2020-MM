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

lnode* merge(lnode* L1, lnode* L2)
{
    lnode* temp = L1;
    while (L1->next != nullptr) 
    { 
        L1 = L1->next; 
    } 
    L1->next = L2;
    return temp;
}

int main()
{
    lnode* l = nullptr;
	l = new lnode(3, l);
	l = new lnode(5, l);
	l = new lnode(8, l);
    show(l);

    lnode* k = nullptr;
    k = new lnode(12, k);
    k = new lnode(15,k);
    k = new lnode(18,k);
    show(k);
    lnode* j = merge(l,k);
    show(j);
    return 0;
}
