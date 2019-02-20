// uso básico de apuntadores
#include <iostream>
using namespace std;

int main( )
{
   int n = 1, m = 2;
   cout << "Direcciones de n, m: " << &n << " " << &m << "\n";
   int* p;

   cout << "Valores de n, m: " << n << " " << m << " " << "\n";
   p = &n;
   *p = 7;
   cout << "Valores de n, m, p: " << n << " " << m << " " << p << "\n";
   p = &m;
   *p = -3;
   cout << "Valores de n, m, p: " << n << " " << m << " " << p << "\n";
}
