// quick_sort es un algoritmo que ordenamiento que particiona la secuencia en dos grupos (los que son menores que un valor pivote y los que no son menores)
// luego ordena recursivamente cada grupo de la partición; este algoritmo es muy sensible a qué tan balanceada quedó la partición: si la partición quedó equilibrada entonces
// realiza ~n*log2(n) comparaciones y escrituras, pero si la partición quedó muy desequilibrada puede tomarle ~n^2 comparaciones y escrituras
#include <algorithm>
#include <iostream>
using namespace std;

// partition es un algoritmo que toma una secuencia, un predicado unario y agrupa primero todos los elementos para los que el predicado es verdadero
// devuelve el fin de la subsecuencia de los elementos que sí cumplen el predicado; este algoritmo está implementado en <algorithm>
template<typename F>
int* partition(int* ini, int* fin, F pred)
{
   int* w = ini;                          // el apuntador w nos indicará a dónde debemos mandar un elemento que sí cumple el predicado
   for (; ini != fin; ++ini) {            // visitamos todos los elementos y siempre avanzamos ini
      if (pred(*ini)) {                   // si *ini cumple el predicado
         swap(*ini, *w++);                // lo mandamos a *w y avanzamos w (el elemento recién mandado no volverá a ser modificado durante la partición)
      }                                   // sólo usamos intercambios y entonces jamás perdemos ningún elemento, sólo los reacomodamos
   }
   return w;                              // w es el fin de lo que sí cumple (porque escribíamos en *w pero avanzábamos w)
}

void quick_sort(int* ini, int* fin)
{
   if (fin - ini >= 2) {
      int* p = partition(ini, fin - 1, [&](int v) {      // elegimos *(fin - 1) como el pivote y particionamos el resto de los elementos
         return v < *(fin - 1);                          // queremos particionar sobre quiénes son menores que el pivote (y van a quedar en el primer grupo)
      });
      swap(*p, *(fin - 1));         // lo de atrás de p es menor que *(fin - 1); movemos a *(fin - 1) a su lugar (es decir, inmediatamente después de todos los que son menores que él)
      quick_sort(ini, p);           // recursión del primer grupo
      quick_sort(p + 1, fin);       // recursión del segundo grupo (el pivote ya no necesita modificarse, ya está en su lugar)
   }
}

int main( )
{
   {
      int arr[10] = { 9, 0, 7, 3, 8, 4, 1, 5, 2, 6 };
      quick_sort(&arr[0], &arr[10]);
      cout << "quick_sort: ";
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
      cout << "quick_sort sobre un arreglo grande, ya ordenado de mayor a menor\n\tel pivote elegido es el ultimo valor de la secuencia (va a tardar)\n";
      quick_sort(&arr[0], &arr[n]);
      cout << "ya acabo, verificando: " << is_sorted(&arr[0], &arr[n]) << "\n";        // is_sorted es de la biblioteca de C++
      /*for (int i = 0; i < n; ++i) {
         cout << arr[i] << " ";
      }
      cout << "\n";*/
   }
}
