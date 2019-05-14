// merge_sort es un algoritmo que ordenamiento que ordena cada mitad y luego hace la mezcla ordenada de las dos mitades en una secuencia auxiliar
// finalmente, copia el resultado almacenado en la secuencia auxiliar a la secuencia original; este algoritmo realiza ~n*log2(n) comparaciones y escrituras
#include <algorithm>
#include <iostream>
using namespace std;

// merge es un algoritmo que toma dos secuencias ordenadas y escribe su mezcla ordenada en una tercera; este algoritmo ya se encuentra implementado en <algorithm>
void merge(int* ini1, int* fin1, int* ini2, int* fin2, int* des)
{
   while (ini1 != fin1 && ini2 != fin2) {             // las dos secuencias aún tienen elementos
      *des++ = (*ini1 < *ini2 ? *ini1++ : *ini2++);   // comparamos los primeros de ambas secuencias, escribimos el menor y avanzamos
   }                                                  // si el ciclo termina es que alguna de las dos secuencias ya se acabó, debemos copiar lo que resta de la otra al destino
   des = copy(ini1, fin1, des);                       // si queda algo en la secuencia #1, lo copiamos; equivalente a    while (ini1 != fin1) { *des++ = *ini1++; }
   des = copy(ini2, fin2, des);                       // si queda algo en la secuencia #2, lo copiamos; equivalente a    while (ini2 != fin2) { *des++ = *ini2++; }
}

void merge_sort(int* ini, int* fin)
{
   if (fin - ini >= 2) {
      int* mitad = ini + (fin - ini) / 2;
      merge_sort(ini, mitad);                         // ordenamos la primera mitad
      merge_sort(mitad, fin);                         // ordenamos la segunda mitad
      int auxiliar[fin - ini];                        // apartamos un arreglo auxiliar
      merge(ini, mitad, mitad, fin, &auxiliar[0]);    // escribimos la mezcla ordenada en el arreglo auxiliar
      copy_n(&auxiliar[0], fin - ini, ini);           // sobreescribimos la secuencia original con el resultado
   }                                                  // copy_n es una variante de copy que, en lugar de tomar el fin de lo que debe copiar, toma cuántos elementos debe copiar
}

int main( )
{
   int arr[10] = { 9, 0, 7, 3, 8, 4, 1, 5, 2, 6 };
   merge_sort(&arr[0], &arr[10]);
   for (int i = 0; i < 10; ++i) {
      cout << arr[i] << " ";
   }
   cout << "\n";
}
