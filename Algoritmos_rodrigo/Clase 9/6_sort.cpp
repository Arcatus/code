// sort ordena una secuencia; por omisión lo hace de menor a mayor pero podemos decirle cómo con una lambda
#include <algorithm>
#include <iostream>
using namespace std;

int main( )
{
   int arr[7] = { 7, 4, 2, 5, 1, 3, 6 };
   cout << "ordenamiento personalizado: de mayor a menor\n";
   sort(&arr[0], &arr[7], [](int a, int b) {
      return a > b;                    // devolver verdadero si a debe ir antes que b (queremos que vaya antes si es mayor)
   });
   for (int i = 0; i < 7; ++i) {
      cout << arr[i] << " ";
   }
   cout << "\n";

   auto pred = [](int a, int b) {      // podemos guardar la función lambda en una variable por si la usaremos varias veces (en este contexto, auto es necesario)
      int pa = a % 2;                  // queremos implementar el siguiente orden: primero pares de menor a mayor, luego impares de mayor a menor
      int pb = b % 2;
      if (pa != pb) {                  // diferente paridad (uno par y otro impar)
         return pa < pb;               // devolvemos verdadero si a es el par
      } else {                         // misma paridad (ambos pares o ambos impares)
         return (pa == 0 ? a < b : a > b);      // si ambos son pares, entonces verdadero si a es el menor
      }                                         // si ambos son impares, entonces verdadero si a es el mayor
   };
   cout << "ordenamiento personalizado: primero pares y luego impares\nlos pares de menor a mayor y los impares de mayor a menor\n";
   sort(&arr[0], &arr[7], pred);
   for (int i = 0; i < 7; ++i) {
      cout << arr[i] << " ";
   }
   cout << "\n";
   cout << "esta el 3? " << binary_search(&arr[0], &arr[7], 3, pred) << "\n";    // el mismo predicado que usamos para ordenar (si usamos alguno) se lo debemos
                                                                                 // pasamos a la busqueda binaria para que esté enterado de cómo está el orden
                                                                                 // aplica también para lower_bound, upper_bound, etc
}
