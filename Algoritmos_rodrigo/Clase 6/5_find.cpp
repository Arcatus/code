// programa que usa find para reemplazar todas ocurrencias de un valor por otro
#include <algorithm>
#include <iostream>
using namespace std;

int main( )
{
   int arr[10] = { 9, 2, 6, 1, 4, 7, 1, 8, 3, 1 };
   int viejo = 1, nuevo = 5;

   int* ini = &arr[0];
   int* fin = &arr[10];
   while (ini != fin) {
      int* p = find(ini, fin, viejo);
      if (p == fin) {   // no está el número que buscamos, no tiene caso seguir
         break;         // se sale del ciclo
      } else {          // sí está el número que buscamos
         *p = nuevo;
         ini = p + 1;
      }
   }

   for (int i = 0; i < 10; ++i) {
      cout << arr[i] << " ";
   }
}
