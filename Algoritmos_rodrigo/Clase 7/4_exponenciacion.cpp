#include <iostream>
using namespace std;

int potencia(int a, int b)
// asunción: b es no negativo
{
   if (b == 0) {
      return 1;
   } else if (b == 1) {
      return a;
   } else {
      int temp = potencia(a, b / 2);
      int res = temp * temp;
      if (b % 2 == 1) {
         res *= a;
      }
      return res;
   }
}

int potencia_simplificado(int a, int b)
// asunción: b es no negativo
{
   if (b <= 1) {
      return (b == 0 ? 1 : a);
   }
   int temp = potencia(a, b / 2);
   int res = temp * temp;
   return res * (b % 2 == 0 ? 1 : a);
}

int main( )
{
   int n = 3, m = 9;
   cout << potencia(n, m) << "\n";

/*
   3^9 = (3^4)^2 * 3                nota: el operador ^ de C++ no calcula potencias
      3^4 = (3^2)^2
         3^2 = (3^1)^2
            3^1 = 3
*/

}
