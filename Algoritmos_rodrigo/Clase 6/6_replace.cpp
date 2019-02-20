// algoritmo replace para reemplazar todas las ocurrencias de un valor con otro
#include <algorithm>
#include <iostream>
using namespace std;

int main( )
{
   int arr[10] = { 9, 2, 6, 1, 4, 7, 1, 8, 3, 1 };
   replace(&arr[0], &arr[10], 1, 5);

   for (int i = 0; i < 10; ++i) {
      cout << arr[i] << " ";
   }
}
