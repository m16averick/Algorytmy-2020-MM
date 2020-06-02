#include <iostream>
#include <vector>

using namespace std;

void show(vector <int> v)
{
    for (int i=0; i<v.size(); i++)
    cout <<v[i] << " ";
}

int main()
{
    vector <int> v;
    vector <int>::iterator it;
    for (int i=0; i<8; i++)
    v.push_back(rand()%10);
    show(v);
    cout << endl;
    int tab[9] = {0};
    for (int i=0; i<8; i++)    tab[v[i]] += 1;

    int j;
    for (int i=0; i<=8; i++)
    {
        j=0;
        while (j<tab[i]) {
            j+=1;
            cout << i;

        }
        
    }
    return 0;
}

