// suma de enteros a apuntadores
#include <iostream>
using namespace std;

int main( )
{
   int arr[4] = { };

   int* p = &arr[0];
   *p = 123;
   p += 2;
   *p = 123;

   int* q = &arr[0];
   *(q + 1) = 456;
   *(q + 3) = 456;

   for (int i = 0; i < 4; ++i) {
      std::cout << arr[i] << " ";
   }
}
