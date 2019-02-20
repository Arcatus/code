// algoritmo reverse para invertir una secuencia
#include <algorithm>
#include <iostream>
using namespace std;

int main( )
{
   int arr[10] = { 9, 2, 6, 1, 4, 7, 5, 8, 3, 1 };
   reverse(&arr[0], &arr[10]);

   for (int i = 0; i < 10; ++i) {
      cout << arr[i] << " ";
   }
}
