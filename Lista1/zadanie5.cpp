#include<iostream>
#include<cstdlib>
using namespace std;

void szukaj(int tab[], int n, int &MIN, int &MAX)
{
	int i = 2;

	if (tab[0]<tab[1])
	{
		MIN = tab[0];
		MAX = tab[1];
	}

	else if(tab[0]>tab[1])
	{
		MIN = tab[1];
		MAX = tab[0];
	}
	
	else
	{
		MIN = MAX = tab[0];
	}
	
	while (i+2 <= n)
	{
		if (tab[i]<tab[i+1])
		{
			// tab[0] należy do zbioru potencjalnych minimów, a tab[1] do maksów
			if (tab[i] < MIN) MIN=tab[i];
			if (tab[i+1] > MAX) MAX=tab[i+1];
			
		}

		if (tab[i]>tab[i+1])
		{
			// tab[0] należy do zbioru potencjalnych maksów, a tab[1] do minimów
			if (tab[i] > MAX) MAX = tab[i];
			if (tab[i+1] < MIN) MIN = tab[i+1];
		}

		i+=2;
	}

}

int main()
{
	int MIN, MAX, tab[] = {1,2,3,4,5,6,7,8,9,10,11,12}; 
	unsigned int n = 12;
	
	szukaj(tab, n, MIN, MAX);
	
	cout<<"MIN: "<<MIN<<"\nMAX: "<<MAX<<endl;
	
	return 0;
}