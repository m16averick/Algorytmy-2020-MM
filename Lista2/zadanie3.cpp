#include<iostream>
#include<cstdlib>
#include<vector>
#include<cmath>

using namespace std;

int skalar(vector<int> x, vector<int> y)
{
    int suma = 0;
    cout << sizeof(x)/8 << endl;
    for (int i=0; i<=sizeof(x)/8; i++)
    {
        suma += x[i]*y[i];
    }
    return suma;

}

int wielomian(int wspolczynniki[], int stopien, int x)
{
    int suma = 0;

    for (int i=stopien; i>=0; i--)
    {
        int wyraz = wspolczynniki[stopien-i];

        wyraz *= pow(x, i);
        //cout << wyraz << endl;
        suma += wyraz;
    }
    return suma;
}


int *iloczyn(int n, int a[], int b[]){              // declare fn2 as returning pointer to array
   int *c;
   for (int i=0; i<=n; i++)
   {
       c[i] = a[i] * b[i];
   }
   return c;
}


int main()
{
    vector<int> x={2, 3, 4}, y={5, 6, 7};

    cout << skalar(x,y) << endl;

    int wspolczynniki[] = {2, 7, -9 };

    cout << wielomian(wspolczynniki, 2, 10) << endl;


    int a[]={1,2,3,4,5}, b[]={1,2,3,4,5};

   cout << iloczyn(5, a, b)[4];

		


}
