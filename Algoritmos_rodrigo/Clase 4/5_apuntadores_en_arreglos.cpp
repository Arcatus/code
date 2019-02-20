// uso básico de apuntadores sobre arreglos
#include <iostream>
using namespace std;

int main( )
{
   int arr[3] = { 0, 0, 0 };
   int* p = &arr[0];

   *p = 9;
   ++p;
   *p = 2;
   ++p;
   *p = 5;

   cout << arr[0] << " " << arr[1] << " " << arr[2] << "\n";
}
