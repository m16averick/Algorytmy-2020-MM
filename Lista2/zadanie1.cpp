//http://www.algorytm.org/dla-poczatkujacych/szukanie-polowkowe-binarne.html

#include<iostream>
#include<cstdlib>
using namespace std;

int szukaj(int x, int t[], int n)
{
	int l = 0, p = n;
	int s, v;

	int counter = 0;

	while( v != x)
	{
		s = (l+p)/2;
		v = t[s];
		if (v > x) p = s-1;
		else if ( v < x) l = s + 1;
		counter++;
		if ( l > p ) return 0;
	}
	cout << "Liczba wykonań pętli: " << counter << endl;
	return s;
}

int main()
{
	int t[] = {0,2,8,16,32,64,128,256,512,1024,2048,4096}; 
	int found = szukaj(8, t, sizeof(t));
	cout << "Pozycja liczby " << t[found] << " jest równa " << found << endl;



	return 0;
}

//Algorytm ten ma bardzo dobrą złożoność obliczeniową wynoszącą O(log n), 
//co oznacza, że czas potrzebny na wyszukanie elementu tą metodą rośnie 
//w sposób logarytmiczny wraz z liniowym wzrostem liczby elementów w przeszukiwanej tablicy.