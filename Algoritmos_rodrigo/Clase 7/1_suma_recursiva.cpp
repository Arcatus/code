#include <iostream>
using namespace std;

int suma(int a, int b)
// asunción: b es no negativo
{
   if (b == 0) {
      return a;
   } else {
      return suma(a + 1, b - 1);
   }
}

int main( )
{
   int n = 7, m = 4;
   cout << suma(n, m) << "\n";

/*
   suma(7, 4) -->
      suma(8, 3) -->
         suma(9, 2) -->
            uma(10, 1) -->
               suma(11, 0) = 11
*/

}


