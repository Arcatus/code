// counting_sort es un algoritmo de ordenamiento (no basado en comparaciones) que lo que hace es contar la frecuencia con la que aparece cada valor de la secuencia
// es el caso específico de un algoritmo más general llamado bucket_sort (ordenamiento por cubeta) cuando la cubeta tiene capacidad 1 https://en.wikipedia.org/wiki/Bucket_sort
// sólo es útil cuando conocemos el rango de valores que pueden tener los valores de la secuencia; toma tiempo ~(n+L) donde L es justo el tamaño del rango de valores
#include <algorithm>
#include <iostream>
using namespace std;

// asumir que los valores de la secuencia está en el rango de 0 a 100; el programa puede tronar si esta asunción no se cumple
/* ejemplo de entrada
   5
   3 1 0 4 0
*/
int main( )
{
   int n;
   cin >> n;

   int arr[n];
   for (int i = 0; i < n; ++i) {
      cin >> arr[i];
   }

   int cuenta[101] = { };              // aquí almacenaremos cuántas veces apareció cada valor; ojo: además de tardar L pasos en llenar todo de ceros, usamos memoria proporcional a L
   for (int i = 0; i < n; ++i) {
      cuenta[arr[i]] += 1;             // arr[i] es el valor de un elemento, lo usaremos como índice de la tabla para indicar que ese valor acaba de aparecer una vez más
   }

   for (int i = 0; i <= 100; ++i) {    // checaremos cuántas veces apareció cada valor en el rango esperado
      for (int j = 0; j < cuenta[i]; ++j) {
         cout << i << " ";             // imprimimos cuenta[i] veces el número i
      }
   }
}
