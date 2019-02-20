// este programa lee enteros, uno tras otro, hasta que encuentra un error o hasta que se acaba la entrada
// luego los imprime en orden contrario al que se leyeron
#include <algorithm>
#include <iostream>
#include <vector>                            // incluiremos <vector> para poder usar un arreglo redimensionable
using namespace std;

int main( )
{
   vector<int> v;                            // el vector comienza está inicialmente vacío

   int n;
   while (cin >> n) {                        // mientras podamos leer un entero en la variable n
      v.push_back(n);                        // guardamos una copia de n en el vector; el valor se agrega al final del mismo
   }                                         // el vector va pidiendo más memoria conforme la va necesitando

   reverse(v.begin( ), v.end( ));            // reverse(&v[0], &v[v.size( )]);
   for (int i = 0; i < v.size( ); ++i) {     // v.size( ) devuelve el número de elementos que tiene el vector en ese momento
      cout << v[i] << " ";                   // accedemos a ellos como si fuera un arreglo
   }
}
