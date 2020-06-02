#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;


int maks_iterative(int t[],int n)
	{

		int x=t[n];
		while(n--) if(t[n]>x) x=t[n]; 
		return x;

	}

int maks_recursive(int t[],int n)
	{
		int x = t[n];
		if (n > 0) 
		{
			int y = maks_recursive(t, n-1);
			if (x < y) x = y;
		}

		return x;

	}

	int maks_recursive2(vector<int> t,int n)
	{
		vector<int> l, p;
		for (int i=0; i <= n/2; i++)
		{
			l.push_back(t[i]);
			p.push_back(t[i+n/2+1]);
		}

			if (n==1) 
			{
				if (l[0] > p[0]) return l[0];
				else return p[0];
			}

			else if (maks_recursive2(l, n/2) > maks_recursive2(p, n/2) )	return maks_recursive2(l, n/2);
			else return maks_recursive2(p,n/2);


	}

int main()
{
	int numer = 8;
	int tablica[]={32229,23337,12312222,252,220, 2239,27,12222,325,320};
	cout << maks_iterative(tablica, numer) << endl;
	cout << maks_recursive(tablica, numer) << endl;
	vector<int> wektor = {32229,23337,12312222,252,220, 2239,27,12222,325,320};
	cout << maks_recursive2(wektor, 8);
		


}
