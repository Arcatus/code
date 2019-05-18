// funciones que calculan el mínimo y el máximo de dos valores, o bien, el mínimo y máximo en una secuencia de valores
// la secuencia no necesita estar ordenada
#include <algorithm>
#include <iostream>
using namespace std;

int main( )
{
   int x = 5, y = 2;
   int menor = min(x, y);
   cout << "el mas pequeño de los dos enteros vale " << menor << "\n";

   int arr[7] = { 7, 4, 2, 5, 1, 8, 6 };
   int mayor = max(arr[0], arr[1]);
   cout << "el mas grande de los primeros dos elementos del arreglo vale " << mayor << "\n";

   int* p = min_element(&arr[0], &arr[7]);
   int* q = max_element(&arr[0], &arr[7]);
   cout << "el mas pequeño de todo el arreglo vale " << *p << " y el mas grande vale " << *q << "\n";

   pair<int*, int*> r = minmax_element(&arr[0], &arr[7]);      // lo mismo pero más barato (si en verdad buscan los dos)
   cout << "el mas pequeño de todo el arreglo vale " << *r.first << " y el mas grande vale " << *r.second << "\n";
}
