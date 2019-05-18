// bubble_sort es un algoritmo de ordenamiento que arrastra el elemento más grande hasta la última posición mediante intercambios,
// luego repite el proceso para arrastrar al segundo más grande, etc; este algoritmo realiza ~n^2 comparaciones y ~n^2 intercambios
// una variante detecta si arreglo ya quedó ordenado y termina; si el arreglo original ya estaba ordenado, realiza ~n comparaciones y 0 intercambios
#include <algorithm>
#include <iostream>
using namespace std;

//sort2 hace siempre una comparación y potencialmente también un intercambio; esta variante devuelve cuántos intercambios hizo
int sort2(int& a, int& b)
{
   if (b < a) {
      swap(a, b);
      return 1;
   } else {
      return 0;
   }
}

void bubble_sort_terminacion(int* ini, int* fin)
{
   for (; fin - ini >= 2; --fin) {
      int intercambios = 0;                                      // contaremos el número de intercambios que realizará la etapa de arrastre
      for (int i = 0; i < fin - ini - 1; ++i) {
         intercambios += sort2(*(ini + i), *(ini + i + 1));      // vamos acumulando lo que nos devuelve sort2
      }
      if (intercambios == 0) {                                   // si no hubo intercambios, ya terminamos y no hay necesidad de continuar
         return;
      }
   }
}

int main( )
{
   {
      int arr[10] = { 9, 0, 7, 3, 8, 4, 1, 5, 2, 6 };
      bubble_sort_terminacion(&arr[0], &arr[10]);
      cout << "bubble_sort con terminacion: ";
      for (int i = 0; i < 10; ++i) {
         cout << arr[i] << " ";
      }
      cout << "\n";
   }

   {
      int n = 100000, arr[n];
      for (int i = 0; i < n; ++i) {          // guardar los valores { 0, 1, 2, ..., n - 2, n - 1 } (de menor a mayor)
         arr[i] = i;
      }
      cout << "bubble_sort* sobre un arreglo grande, ya ordenado de menor a mayor\n";
      bubble_sort_terminacion(&arr[0], &arr[n]);
      cout << "ya acabo, verificando: " << is_sorted(&arr[0], &arr[n]) << "\n";        // is_sorted es de la biblioteca de C++
      /*for (int i = 0; i < n; ++i) {
         cout << arr[i] << " ";
      }
      cout << "\n";*/
   }

   {
      int n = 100000, arr[n];
      for (int i = 0; i < n; ++i) {          // guardar los valores { n - 1, n - 2, ..., 2, 1, 0 } (de mayor a menor)
         arr[i] = n - 1 - i;
      }
      cout << "bubble_sort* sobre un arreglo grande, ya ordenado de mayor a menor (tardara)\n";
      bubble_sort_terminacion(&arr[0], &arr[n]);
      cout << "ya acabo, verificando: " << is_sorted(&arr[0], &arr[n]) << "\n";        // is_sorted es de la biblioteca de C++
      /*for (int i = 0; i < n; ++i) {
         cout << arr[i] << " ";
      }
      cout << "\n";*/
   }
}
