// algoritmo find_if para encontrar la primera ocurrencia de un valor que cumple un predicado
#include <algorithm>
#include <iostream>
using namespace std;

bool es_par(int n)
{
   return n % 2 == 0;
}

int main( )
{
   int arr[10] = { 9, 5, 3, 4, 6, 1, 2, 7, 1, 8 };
   int* p = find_if(&arr[0], &arr[10], es_par);

   if (p == &arr[10]) {
      cout << "No encontramos ningun par\n";
   } else {
      cout << "Si encontramos un par que vale " << *p << "\n";
      cout << "La posicion relativa al inicio del arreglo es " << p - &arr[0] << "\n";
   }
}
