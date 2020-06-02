#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int h(int k)
{
    double phi=(1-sqrt(5)/2);
    return floor((1<<30)*((k*phi)-floor(k*phi)));
}

int has(string s)
{
    int tmp=1;
    for (int i=0; i<s.size(); i++)
    {
        tmp = h(tmp+1)*s[1];
    }
    return tmp;
}

int main()
{
    cout << has("Ala ma kota") << endl;
}