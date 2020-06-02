#include<iostream> 
using namespace std; 
  
int getMax(int arr[], int n) 
{ 
    int mx = arr[0]; 
    for (int i = 1; i < n; i++) 
        if (arr[i] > mx) 
            mx = arr[i]; 
    return mx; 
} 
  
void countSort(int arr[], int n, int exp) 
{ 
    //dla każdej cyfry przygotowujemy licznik i ustawiamy go na 0
    int output[n];
    int i, count[10] = {0}; 
  
  // do elementu tablicy output, którego indeks jest równy wartości elementu tablicy arr dodaję 1 kiedy nastąpi wystąpienie
    for (i = 0; i < n; i++) 
        count[ (arr[i]/exp)%10 ]++; 
  // sumuję każdy element z poprzednim
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
  // 
    for (i = n - 1; i >= 0; i--) 
    { 
        // każdy element tablicy wejściowej przyrównuję jego indeksowi w tablicy wyjściowej
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
        // i odejmuję 1 skoro element jest już przypisany
        count[ (arr[i]/exp)%10 ]--; 
    } 
  //zamieniam elementy tablicy wejściowej na wyjściowe
    for (i = 0; i < n; i++) 
        arr[i] = output[i]; 
} 
  
void radixsort(int arr[], int n) 
{ 
    int m = getMax(arr, n); 
  
    for (int exp = 1; m/exp > 0; exp *= 10) 
        countSort(arr, n, exp); 
} 
  
void print(int arr[], int n) 
{ 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
} 
  

int main() 
{ 
    int arr[] = { 1, 34, 123, 321, 432, 132, 543, 651, 91, 32, 987, 910, 643, 641, 12, 342, 498, 987, 965, 122, 121, 431, 350}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    radixsort(arr, n); 
    print(arr, n); 
    return 0; 
} 