// este programa ejemplifica el uso de map<K, T> de la biblioteca, el cual implementa un árbol ordenado de búsqueda sin claves duplicadas donde cada clave tiene un valor adicional asociado
#include <iostream>
#include <map>
using namespace std;

template<typename K, typename T>
void imprime(const map<K, T>& m)
{
   cout << "{ ";
   for (auto i = m.begin( ); i != m.end( ); ++i) {
      cout << "(" << i->first << ", " << i->second << ") ";
   }
   cout << "} \n";
}

int main( )
{
   map<string, double> m;
   m["gatito"] = 3.1416;
   cout << m["gatito"] << "\n";

   m.emplace("perrito", 2.7182);
   m.insert({ "galleta", 12345.6 });
   cout << m.size( ) << " claves distintas\n";
   imprime(m);
   cout << "\n";

   auto iter = m.find("gatito");       // map busca por clave
   if (iter == m.end( )) {             // find devuelve el fin si el elemento no está en el map
      cout << "No esta la clave \"gatito\"\n";
   } else {
      cout << "Si esta la clave \"gatito\": " << iter->first << " " << iter->second << "\n";
   }

   if (m.find("cotorrito") == m.end( )) {
      cout << "No esta la clave \"cotorrito\"\n";
   } else {
      cout << "No esta la clave \"cotorrito\"\n";
   }

   cout << "Borraremos algunas claves\n";
   imprime(m);
   m.erase("gatito");
   imprime(m);
   auto temp = m.find("perrito");
   m.erase(temp);                   // pueden usar erase con el valor de la clave y con un iterador que se obtuvo al buscar la clave
   imprime(m);

   auto info = m.emplace("galleta", 20);     // el tipo real de info es pair<map<K, T>::iterator, bool> con K = string, T = double en este caso
   if (info.second) {                        // info.first tiene un iterador al elemento con la clave dada; info.second tiene un booleano que indica si la inserción se realizó
      cout << "Se pudo realizar la insercion de (\"galleta\", 20)\n";
   } else {                                  // la inserción falla si ya existe la clave; multimap<K, T> permite claves duplicadas
      cout << "No se pudo realizar la insercion de (\"galleta\", 20)\n";
   }
   cout << info.first->first << " es la clave del nodo y " << info.first->second << " es el valor asociado\n";
}                                            // desreferenciar un map<string, double>::iterator devuelve un pair<string, double>
