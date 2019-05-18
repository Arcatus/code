// programa que ejemplifica otras utilidades de vector
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main( )
{
   vector<int> v(10, -3);     // vector con 10 elementos iniciales, todos con valor -3
   v[3] = 0;
   v[4] = 7;
   sort(v.begin( ), v.end( ));

   for (int n : v) {          // iteración con for de rango
      cout << n << " ";
   }
   cout << "\n";

   auto p = lower_bound(v.begin( ), v.end( ), 9);        // vector<int>::iterator
   if (p == v.end( )) {
      cout << "no hay elementos mayores o iguales a 9\n";
   } else {
      cout << "el primer elemento no menor que 9 es " << *p << "\n";
   }

   vector<int> w = v;         // copia del vector
   w[0] = -1000;              // modificamos w (v no se modifica)
   cout << "v[0] = " << v[0] << ", w[0] = " << w[0] << "\n";
}
