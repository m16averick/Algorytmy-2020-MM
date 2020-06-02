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

int main()
{
    lnode* l = nullptr;
	l = new lnode(3, l);
	l = new lnode(5, l);
	l = new lnode(8, l);
    show(l);
    reverse(l);
    show(l);
    return 0;
}


/*
8 5 3

op: 5 3

L: 8
temp: 5 3
op: 3

show

temp: 5 8
L: 58

temp: 3
op: null

show
temp: 3 5 8
L: 3 5 8
*/