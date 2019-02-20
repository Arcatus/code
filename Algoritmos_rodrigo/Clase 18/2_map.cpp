// este programa ejemplifica el uso de map<K, T> de la biblioteca, el cual implementa un árbol ordenado de búsqueda sin claves duplicadas
#include <iostream>
#include <map>
#include <utility>                     // en <utility> está pair, por si lo quieren usar aunque no usen map
using namespace std;

int main( )
{
   map<string, int> m;
   m.insert({ "cotorrito", 3});        // construye un pair<string, int> y lo inserta
   m.insert({ "gatito", 5 });          // construye un pair<string, int> y lo inserta
   m.emplace("perrito", 1);            // con .emplace pueden evitar usar las llaves; el primer parámetro es la clave y el segundo es el valor

   auto iter = m.begin( );
   pair<string, int> v1 = *iter;
   ++iter;
   string v2_clave = (*iter).first;  int v2_valor = (*iter).second;
   ++iter;
   string v3_clave = iter->first;    int v3_valor = iter->second;
   ++iter;
   std::cout << "{ (" << v1.first << " " << v1.second << ") (" << v2_clave << " " << v2_valor << ") (" << v3_clave << " " << v3_valor << ") }\n";
   std::cout << "ya llegamos al fin? " << (iter == m.end( )) << "\n";

   std::cout << "{ ";
   for (const auto& v : m) {
      std::cout << "(" << v.first << " " << v.second << ") ";
   }
   std::cout << "} \n";
}
