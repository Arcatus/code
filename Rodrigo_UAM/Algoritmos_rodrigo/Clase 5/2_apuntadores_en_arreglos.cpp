// uso básico de apuntadores sobre arreglos
#include <iostream>
using namespace std;

int main( )
{
   int arr[10] = { };
   for (int* p = &arr[0]; p < &arr[10]; ++p) {
      *p = 5;
   }

   for (int i = 0; i < 10; ++i) {
      cout << arr[i] << " ";
   }
}
