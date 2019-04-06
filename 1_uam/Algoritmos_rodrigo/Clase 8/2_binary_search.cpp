// binary_search está en <algorithm> pero la de abajo es una implementación parecida a la de la biblioteca
#include <iostream>
using namespace std;

bool binary_search(int* ini, int* fin, int v)
{
   if (ini == fin) {
      return false;
   } else {                         // en clase usamos un caso base adicional cuando fin - ini == 1, pero el código del else funciona todavía bien para este caso
      int* mitad = ini + (fin - ini) / 2;
      if (v == *mitad) {
         return true;
      } else if (v < *mitad) {
         return binary_search(ini, mitad, v);
      } else if (v > *mitad) {      // innecesario, lo pongo por claridad
         return binary_search(mitad + 1, fin, v);
      }
   }
}

int main( )
{
   int arr[10] = { 1, 3, 4, 7, 12, 18, 23, 31, 37, 44 };
   cout << binary_search(&arr[0], &arr[10], 0) << "\n";
   cout << binary_search(&arr[0], &arr[10], 1) << "\n";
   cout << binary_search(&arr[0], &arr[10], 10) << "\n";
   cout << binary_search(&arr[0], &arr[10], 18) << "\n";
   cout << binary_search(&arr[0], &arr[10], 44) << "\n";
   cout << binary_search(&arr[0], &arr[10], 47) << "\n";
}
