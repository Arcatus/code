// insertion_sort es un algoritmo de ordenamiento que mantiene una subsecuencia ordenada de los elementos que ya vio, de modo que cuando ve un elemento nuevo,
// lo coloca en el lugar en el que debe ir en la subsecuencia ordenada que ya tenía; este algoritmo realiza ~n*log2(n) comparaciones y ~n^2 intercambios
#include <algorithm>
#include <iostream>
using namespace std;

void insertion_sort(int* ini, int* fin)
{
   for (int* i = ini; i != fin; ++i) {          // la subsecuencia ordenada es [ini, i) mientras que *i es el elemento nuevo que queremos considerar
      int* p = lower_bound(ini, i, *i);         // buscamos dónde debemos insertar *i sobre la subsecuencia ordenada
      rotate(p, i, i + 1);                      // ponemos *i al frente de la subsecuencia, desplazando en una posición a los elementos que quedarán a su derecha
   }
}

void insertion_sort_v2(int* ini, int* fin)      // por si no quieren usar rotate
{
   for (int* i = ini; i != fin; ++i) {
      int* p = lower_bound(ini, i, *i);
      for (int* j = i; j != p; --j) {           // debemos arrastrar *i hasta *p; sea j = i intercambiaremos con el elemento que esté atras y retrocederemos j
         swap(*j, *(j - 1));                    // no debemos llegar a j == p porque swap(*j, *(j - 1)) tocaría al que elemento que está atrás de p, y ése no debe ser afectado
      }
   }                                            // piensen en qué tan feo se vería el código si también reemplazan lower_bound con una bola de ciclos e ifs, los sistemas reales
}                                               // se implementan descomponiendo el trabajo en funciones pequeñas y luego llamándolas, de modo que es más obvio lo que hace el sistema

int main( )
{
   {
      int arr[10] = { 9, 0, 7, 3, 8, 4, 1, 5, 2, 6 };
      insertion_sort(&arr[0], &arr[10]);
      cout << "insertion_sort con rotate: ";
      for (int i = 0; i < 10; ++i) {
         cout << arr[i] << " ";
      }
      cout << "\n";
   }

   {
      int arr[10] = { 9, 0, 7, 3, 8, 4, 1, 5, 2, 6 };
      insertion_sort(&arr[0], &arr[10]);
      cout << "insertion_sort sin rotate: ";
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
      cout << "insertion_sort sobre un arreglo grande, ya ordenado de menor a mayor\n";
      insertion_sort(&arr[0], &arr[n]);
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
      cout << "insertion_sort sobre un arreglo grande, ya ordenado de mayor a menor (tardara)\n";
      insertion_sort(&arr[0], &arr[n]);
      cout << "ya acabo, verificando: " << is_sorted(&arr[0], &arr[n]) << "\n";        // is_sorted es de la biblioteca de C++
      /*for (int i = 0; i < n; ++i) {
         cout << arr[i] << " ";
      }
      cout << "\n";*/
   }
}
