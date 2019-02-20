// algoritmo fill para llenar de valores un arreglo
#include <algorithm>
#include <iostream>
using namespace std;

int main( )
{
   int arr[10];
   fill(&arr[0], &arr[10], 5);
   fill(&arr[2], &arr[7], 3);

   for (int i = 0; i < 10; ++i) {
      cout << i << ": " << arr[i] << "\n";
   }
}
