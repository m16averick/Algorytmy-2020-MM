#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


// n = floor( (x mod 10^k) / 10^(k-1) )
int kta(int x, int k) //kta od konca cyfra
{   
    int p = pow(10,k);
    int z = x%p;
    int n = floor(z / pow(10,(k-1)));
    return n;
}

int n(int x) //ilosc cyfr
{
    int i = 0;
    while(x>0)
    {
        x/=10;
        i+=1;
    }
    return i;
}

int main()
{
    int x = 50342;
    cout << kta(x, 3) << endl;
    cout << n(x) << endl;

    return 0;
}

