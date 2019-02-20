// upper_bound devuelve el apuntador al primer elemento mayor que el elemento buscado, o el fin si ninguno es mayor
// upper_bound es una versión de búsqueda binaria, la secuencia debe estar ordenada
#include <algorithm>
#include <iostream>
using namespace std;

int main( )
{
   int arr[7] = { 1, 4, 4, 5, 8, 10, 22 };
   int* p1 = upper_bound(&arr[0], &arr[7], 5);

   if (p1 == &arr[7]) {
      cout << "no existe ningun elemento > 5\n";
   } else {
      cout << "si existe un elemento > 5, el primero vale " << *p1 << "\n";
   }

   int* p2 = upper_bound(&arr[0], &arr[7], 9);
   
   if (p2 == &arr[7]) {
      cout << "no existe ningun elemento > 9\n";
   } else {
      cout << "si existe un elemento > 9, el primero vale " << *p2 << "\n";
   }

   int* p3 = upper_bound(&arr[0], &arr[7], 30);
   if (p3 == &arr[7]) {
      cout << "no existe ningun elemento > 30\n";
   } else {
      cout << "si existe un elemento > 30, el primero vale " << *p3 << "\n";
   }
}
