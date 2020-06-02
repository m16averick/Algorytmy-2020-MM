#include <iostream>
#include <array>
using namespace std;


//metoda polega na przypisaniu k pierwszych wartości zmiennej pomocniczej i przesunięciu pozostałych wyrazów o k w prawo
void *przesuwacz(int tablica[], int n, int k)
{

    int temp[10];
    for (int j=0; j<k; j++)
    {
        temp[j] = tablica[n-j];
    }

    for (int i=n; i>0; i--)
    {
        tablica[i] = tablica[i-k];
    }

    for (int j=0; j<k; j++)
    {
        tablica[j] = temp[j];
    }


    return 0;

}

void show(int tab[], int size)
{
    for (int i=0; i<=size; i++)
    {
        cout << tab[i] << " ";
    }
}

int main()
{
    int tablica[]={1,2,3,4,5,6};
    przesuwacz(tablica, 5, 3);
    show(tablica, 5);
    return 0;
}

