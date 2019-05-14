// selection_sort es un algoritmo de ordenamiento que ubica al elemento más grande únicamente mediante comparaciones y lo coloca en su lugar con un intercambio,
// luego repite el proceso para el segundo más grande, etc; este algoritmo realiza ~n^2 comparaciones y ~n intercambios
#include <algorithm>
#include <iostream>
using namespace std;

void selection_sort(int* ini, int* fin)
{
   while (ini != fin) {
      int* p = max_element(ini, fin);        // buscamos el elemento más grande
      swap(*p, *--fin);                      // lo colocamos en la última posición, que es *(fin - 1), pero aprovechamos para decrementar el fin en la misma línea
   }
}

int main( )
{
   {
      int arr[10] = { 9, 0, 7, 3, 8, 4, 1, 5, 2, 6 };
      selection_sort(&arr[0], &arr[10]);
      cout << "selection_sort: ";
      for (int i = 0; i < 10; ++i) {
         cout << arr[i] << " ";
      }
      cout << "\n";
   }

   {
      int n = 100000, arr[n];
      for (int i = 0; i < n; ++i) {
         arr[i] = i;
      }
      cout << "selection_sort sobre un arreglo grande (va a tardar)\n";
      selection_sort(&arr[0], &arr[n]);
      cout << "ya acabo, verificando: " << is_sorted(&arr[0], &arr[n]) << "\n";        // is_sorted es de la biblioteca de C++
      /*for (int i = 0; i < n; ++i) {
         cout << arr[i] << " ";
      }
      cout << "\n";*/
   }
}
