// este programa ejemplifica el uso de set<T> de la biblioteca, el cual implementa un árbol ordenado de búsqueda sin claves duplicadas
#include <iostream>
#include <set>
using namespace std;

int main( )
{
   set<int> s;
   s.insert(5);
   s.insert(1);
   s.insert(3);

   auto iter = s.begin( );
   int v1 = *iter;
   ++iter;
   int v2 = *iter;
   ++iter;
   int v3 = *iter;
   ++iter;
   std::cout << "{ " << v1 << " " << v2 << " " << v3 << " }\n";
   std::cout << "ya llegamos al fin? " << (iter == s.end( )) << "\n";

   std::cout << "{ ";
   for (int v : s) {
      std::cout << v << " ";
   }
   std::cout << "} \n";
}
