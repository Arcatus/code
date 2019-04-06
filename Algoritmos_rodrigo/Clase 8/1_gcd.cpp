   // gcd es el máximo común divisor (greatest common divisor) y se puede implementar fácilmente de manera recursiva
#include <iostream>
using namespace std;

int gcd(int a, int b)
// asunción: a, b son enteros no negativos
{
   if (b == 0) {
      return a;
   } else {
      return gcd(b, a % b);
   }
}

/*
int gcd(int a, int b)      // simplificado
{
   return (b == 0 ? a : gcd(b, a % b));
}

int gcd(int a, int b)      // iterativo
{
   while (b != 0) {
      int temp = a % b;
      a = b;
      b = temp;
   }
   return a;
}
*/

int main( )
{
   int a, b;
   cin >> a >> b;
   cout << gcd(a, b) << '\n';
}
