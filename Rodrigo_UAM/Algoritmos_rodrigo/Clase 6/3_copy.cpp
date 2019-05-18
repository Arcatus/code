// algoritmo copy para copiar una secuencia en otra
#include <algorithm>
#include <iostream>
using namespace std;

int main( )
{
   int arr[5] = { 9, 2, 6, 1, 4 };

   int brr[5];
   copy(&arr[0], &arr[5], &brr[0]);
   for (int i = 0; i < 5; ++i) {
      cout << brr[i] << " ";
   }
   cout << "\n";

   int crr[10];
   copy(&arr[0], &arr[5], &crr[0]);
   copy(&arr[0], &arr[5], &crr[5]);
   for (int i = 0; i < 10; ++i) {
      cout << crr[i] << " ";
   }
   cout << "\n";
}
