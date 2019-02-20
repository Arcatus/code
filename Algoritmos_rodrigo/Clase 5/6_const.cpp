// interacción entre apuntadores y const
#include <iostream>
using namespace std;

int main( )
{
   const int n = 5;
   n = 10;           // error de compilación, n es const y no admite modificaciones
   int* p = &n;      // error de compilación, el apuntador no respecta const

   const int* q = &n;
   *q = 10;          // error de compilación, el apuntador respeta const
   cout << *q << "\n";
}
