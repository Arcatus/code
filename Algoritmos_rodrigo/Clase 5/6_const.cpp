// interacci�n entre apuntadores y const
#include <iostream>
using namespace std;

int main( )
{
   const int n = 5;
   n = 10;           // error de compilaci�n, n es const y no admite modificaciones
   int* p = &n;      // error de compilaci�n, el apuntador no respecta const

   const int* q = &n;
   *q = 10;          // error de compilaci�n, el apuntador respeta const
   cout << *q << "\n";
}
