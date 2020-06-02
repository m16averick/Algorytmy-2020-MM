#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>

using namespace std;

vector<int> opener(string name)
{
	int nr_linii = 1;
	string wyrazenie;
	vector <int> wyrazenieA;

	fstream plik;
	plik.open(name, ios::in);

	while(getline(plik, wyrazenie, ' '))
	{
		if(wyrazenie != " ") wyrazenieA.push_back(std::stoi(wyrazenie));
		nr_linii++;	
	}

	plik.close();
	return wyrazenieA;
}

void printer(int stopien, vector<int> wyraz)
{
	cout << stopien << " ";
	for (int i=0; i<wyraz.size(); i++)
	{
		cout << wyraz[i] << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> wyrazA =  opener("a.txt");

	int stopienA = wyrazA[0];
	wyrazA.erase(wyrazA.begin());

	vector<int> wyrazB =  opener("b.txt");
	int stopienB = wyrazB[0];
	wyrazB.erase(wyrazB.begin());

	cout << stopienA << endl << wyrazA[0] << endl;
	cout << stopienB << endl << wyrazB[0] << endl;

	int stopienC = stopienA + stopienB;
//	cout << wyrazA[wyrazA.back()];
	vector<int> wyrazC;
	wyrazC.resize(stopienC+1);
//	for (int i=0; i<10; i++) wyrazC.push_back(0);

//	wyrazC.resize(stopienC+2);
	for (int i=0; i<stopienC; i++)
	{

		for (int j=0; j<=stopienB; j++)
		{
			wyrazC[i+j] += wyrazA[i] * wyrazB[j];
		}

	}

	printer(stopienC, wyrazC);

	return 0;
}