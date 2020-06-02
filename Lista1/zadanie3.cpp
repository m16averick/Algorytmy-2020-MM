// L1z3.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

using namespace std;

double oblicz(double a[], int n, double x)
{
	double suma=0;
	for (int i=0; i<=n; i++)
	{
		double skladowa=a[i];

		for (int j=0; j<n-i; j++)
		{
			skladowa *= x;
		}
			suma += skladowa;
	}

		return suma;
}

int main()
{
	double an[4] = { 2.0, 3.0, 4, 5 };
	std::cout << oblicz(an, 3, 15);
}
