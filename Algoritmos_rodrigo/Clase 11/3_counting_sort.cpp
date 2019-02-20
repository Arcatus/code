// counting_sort es un algoritmo de ordenamiento (no basado en comparaciones) que lo que hace es contar la frecuencia con la que aparece cada valor de la secuencia
// es el caso espec�fico de un algoritmo m�s general llamado bucket_sort (ordenamiento por cubeta) cuando la cubeta tiene capacidad 1 https://en.wikipedia.org/wiki/Bucket_sort
// s�lo es �til cuando conocemos el rango de valores que pueden tener los valores de la secuencia; toma tiempo ~(n+L) donde L es justo el tama�o del rango de valores
#include <algorithm>
#include <iostream>
using namespace std;

// asumir que los valores de la secuencia est� en el rango de 0 a 100; el programa puede tronar si esta asunci�n no se cumple
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

   int cuenta[101] = { };              // aqu� almacenaremos cu�ntas veces apareci� cada valor; ojo: adem�s de tardar L pasos en llenar todo de ceros, usamos memoria proporcional a L
   for (int i = 0; i < n; ++i) {
      cuenta[arr[i]] += 1;             // arr[i] es el valor de un elemento, lo usaremos como �ndice de la tabla para indicar que ese valor acaba de aparecer una vez m�s
   }

   for (int i = 0; i <= 100; ++i) {    // checaremos cu�ntas veces apareci� cada valor en el rango esperado
      for (int j = 0; j < cuenta[i]; ++j) {
         cout << i << " ";             // imprimimos cuenta[i] veces el n�mero i
      }
   }
}
