// algoritmo find para buscar la primera ocurrencia de un valor en una secuencia
#include <algorithm>
#include <iostream>
using namespace std;

int main( )
{
   int arr[5] = { 9, 2, 6, 1, 4 };
   int* p = find(&arr[0], &arr[5], 6);
   if (p == &arr[5]) {
      cout << "No hay ningun 6\n";
   } else {
      cout << "Si hay un 6, cambiandolo por un 7\n";
      *p += 1;
   }

   int* q = find(&arr[0], &arr[5], 6);
   if (q == &arr[5]) {
      cout << "Buscamos de nuevo un 6, pero ya no hay\n";
   }
}
