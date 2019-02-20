// lower_bound devuelve el apuntador al primer elemento no menor que el elemento buscado, o el fin todos son menores
// lower_bound es una versión de búsqueda binaria, la secuencia debe estar ordenada
#include <algorithm>
#include <iostream>
using namespace std;

// implementación similar a la de la biblioteca
// devuelve el apuntador al primer elemento no menor que v, o el fin si todos son menores
// (en términos más simples, devuelve el apuntador al primer elemento mayor o igual)
int* lower_bound(int* ini, int* fin, int v)
{
   if (fin - ini <= 2) {                        // en clase vimos por qué el caso base debe ser cuando nos quedan dos elementos (o menos)
      return find_if(ini, fin, [&](int actual) {
         return actual >= v;
      });
   }

   int* mitad = ini + (fin - ini) / 2;
   if (*mitad < v) {                            // si *mitad < v, mitad no nos sirve
      return lower_bound(mitad + 1, fin, v);    // lo excluimos de la recursión y nos vamos del lado derecho
   } else {                                     // sabemos que *mitad >= v, hacemos recursión del lado izquierdo
      return lower_bound(ini, mitad + 1, v);    // no debemos excluir mitad porque no sabemos si *mitad es el primer valor >=
   }
}

int main( )
{
   int arr[7] = { 1, 4, 4, 5, 8, 10, 22 };
   int* p1 = lower_bound(&arr[0], &arr[7], 5);
   if (p1 == &arr[7]) {
      cout << "no existe ningun elemento >= 5\n";
   } else {
      cout << "si existe un elemento >= 5, el primero vale " << *p1 << "\n";
   }

   int* p2 = lower_bound(&arr[0], &arr[7], 9);
   if (p2 == &arr[7]) {
      cout << "no existe ningun elemento >= 9\n";
   } else {
      cout << "si existe un elemento >= 9, el primero vale " << *p2 << "\n";
   }

   int* p3 = lower_bound(&arr[0], &arr[7], 30);
   if (p3 == &arr[7]) {
      cout << "no existe ningun elemento >= 30\n";
   } else {
      cout << "si existe un elemento >= 30, el primero vale " << *p3 << "\n";
   }
}
