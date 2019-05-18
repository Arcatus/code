#include <iostream>
using namespace std;

int producto_2k(int a, int b)
// asunción: b es una potencia de 2
{
   if (b == 1) {
      return a;
   } else {
      return producto_2k(a * 2, b / 2);
   }
}

int main( )
{
   int n = 32, m = 8;
   cout << producto_2k(n, m) << "\n";

/*
   producto_2k(32, 8) -->
      producto_2k(64, 4) -->
         producto_2k(128, 2) -->
            producto_2k(256, 1) = 256
*/

}


