// sort ordena una secuencia; por omisión lo hace de menor a mayor pero podemos decirle cómo
#include <algorithm>
#include <iostream>
using namespace std;

// predicado de ordenamiento: devolver verdadero si a debe ir antes que b con toda certeza
// ejemplo: primero pares y luego impares, los pares de menor a mayor y los impares de menor a mayor
bool primero_pares(int a, int b)
{
   int pa = a % 2;
   int pb = b % 2;
   if (pa == pb) {      // misma paridad (ambos pares o ambos impares)
      return a < b;     // devolvemos verdadero si a es el menor
   } else {             // diferente paridad (uno par y otro impar)
      return pa < pb;   // devolvemos verdadero si a es el par (en otras palabras, pa == 0 && pb == 1)
   }
}

int main( )
{
   int arr[7] = { 7, 4, 2, 5, 1, 3, 6 };

   cout << "ordenamiento por omisión (de menor a mayor)\n";
   sort(&arr[0], &arr[7]);
   for (int i = 0; i < 7; ++i) {
      cout << arr[i] << " ";
   }
   cout << "\n";

   cout << "ordenamiento personalizado: primero pares y luego impares\nlos pares de menor a mayor y los impares de menor a mayor\n";
   sort(&arr[0], &arr[7], primero_pares);
   for (int i = 0; i < 7; ++i) {
      cout << arr[i] << " ";
   }
   cout << "\n";
}
