#include <iostream>

using namespace std;

int rekurencja(int x, int n)
{
    if (n == 0) return 1;
    else if (n == 2) return x * x;
    else if (n%2 == 0)
    {
        int pet = rekurencja(x, n/2);
        return pet * pet;
    }
        else if (n%2 == 1)
    {
        int pet = rekurencja(x, (n-1)/2);
        return pet * pet * x;
    }
}

int iterative(int x, int n)
{
    if (n==0) return 1;
    int value=x;

    for (int i=1; i<n; i++)
    {
        value*=x;
    }

    return value;
}


int main()
{
	int p1 = rekurencja(2, 3);
	std::cout << p1 << endl;
	int p2 = iterative(2, 3);
	std::cout << p2;
	//std::cout << p1(2, 3);
}

