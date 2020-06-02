#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>

using namespace std;


vector<int> opener(string name)
{

	fstream plik;
	plik.open(name, ios::in | ios::binary);
	vector<int> contents(istreambuf_iterator<char>(plik), (istreambuf_iterator<char>()));


	plik.close();
	return contents;
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
	vector<int> ascii_counter, tekstful;
	ascii_counter.resize(256);
	
	fstream plik;
	plik.open("tekst.txt", ios::in | ios::binary);
	while (plik)
	
	{
		int i = plik.get();
		ascii_counter[i]+=1;
	}
	

	for (int i=0; i<256; i++)
	{
		if (ascii_counter[i] > 0) cout << i << " " << ascii_counter[i] << endl;
	}

	return 0;
}