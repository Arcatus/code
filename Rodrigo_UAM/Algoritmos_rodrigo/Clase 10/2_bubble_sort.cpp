// bubble_sort es un algoritmo de ordenamiento que arrastra el elemento más grande hasta la última posición mediante intercambios,
// luego repite el proceso para arrastrar al segundo más grande, etc; este algoritmo realiza ~n^2 comparaciones y ~n^2 intercambios
#include <algorithm>
#include <iostream>
using namespace std;

//sort2 hace siempre una comparación y potencialmente también un intercambio
void sort2(int& a, int& b)
{
   if (b < a) {
      swap(a, b);
   }
}

// implementación recursiva de bubble_sort
void bubble_sort(int* ini, int* fin)
{
   if (fin - ini >= 2) {                           // nada que hacer si hay uno o cero elementos
      for (int i = 0; i < fin - ini - 1; ++i) {    // para arrastrar el elemento mayor hasta la última posición de una
         sort2(*(ini + i), *(ini + i + 1));        // secuencia de n elementos, necesitamos n - 1 invocaciones a sort2
      }
      bubble_sort(ini, fin - 1);                   // recursión: el mayor elemento ya quedó en la última posición, no necesitamos volver a verlo
   }
}

// implementación iterativa
void bubble_sort_v2(int* ini, int* fin)
{
   for (; fin - ini >= 2; --fin) {                    // el ciclo sólo se hace si fin - ini >= 2 y decrementamos fin después hacer lo de adentro
      for (int i = 0; i < fin - ini - 1; ++i) {       // para arrastrar el elemento mayor hasta la última posición de una
         sort2(*(ini + i), *(ini + i + 1));           // secuencia de n elementos, necesitamos n - 1 invocaciones a sort2
      }
   }
}

int main( )
{
   {
      int arr[10] = { 9, 0, 7, 3, 8, 4, 1, 5, 2, 6 };
      bubble_sort(&arr[0], &arr[10]);
      cout << "bubble_sort recursivo: ";
      for (int i = 0; i < 10; ++i) {
         cout << arr[i] << " ";
      }
      cout << "\n";
   }

   {
      int arr[10] = { 9, 0, 7, 3, 8, 4, 1, 5, 2, 6 };
      bubble_sort_v2(&arr[0], &arr[10]);
      cout << "bubble_sort iterativo: ";
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
      cout << "bubble_sort sobre un arreglo grande, ya ordenado de menor a mayor (tardara)\n";
      bubble_sort_v2(&arr[0], &arr[n]);
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
      cout << "bubble_sort sobre un arreglo grande, ya ordenado de mayor a menor (tardara)\n";
      bubble_sort_v2(&arr[0], &arr[n]);
      cout << "ya acabo, verificando: " << is_sorted(&arr[0], &arr[n]) << "\n";        // is_sorted es de la biblioteca de C++
      /*for (int i = 0; i < n; ++i) {
         cout << arr[i] << " ";
      }
      cout << "\n";*/
   }
}
