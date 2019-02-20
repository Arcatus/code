// este programa ejemplifica el uso de set<T> de la biblioteca, el cual implementa un árbol ordenado de búsqueda sin claves duplicadas
#include <iostream>
#include <set>
using namespace std;

template<typename T>
void imprime(const set<T>& s)
{
   cout << "{ ";
   for (auto i = s.begin( ); i != s.end( ); ++i) {
      cout << *i << " ";
   }
   cout << "} \n";
}

int main( )
{
   set<int> s;
   s.insert(5);
   s.insert(3);
   s.insert(1);
   s.insert(3);
   s.insert(4);
   cout << s.size( ) << " claves distintas\n";
   imprime(s);
   cout << "\n";

   if (s.find(5) == s.end( )) {        // find devuelve el fin si el elemento no está en el set
      cout << "No esta el 5\n";
   } else {
      cout << "Si esta el 5\n";
   }

   if (s.find(7) == s.end( )) {
      cout << "No esta el 7\n";
   } else {
      cout << "Si esta el 7\n";
   }

   cout << "Borraremos algunas claves\n";
   imprime(s);
   s.erase(5);
   imprime(s);
   auto iter = s.find(4);
   s.erase(iter);                   // pueden usar erase con el valor de la clave y con un iterador que se obtuvo al buscar la clave
   imprime(s);

   auto info = s.insert(3);         // el tipo real de info es pair<set<T>::iterator, bool> con T = int en este caso
   if (info.second) {               // info.first tiene un iterador al elemento con la clave dada; info.second tiene un booleano que indica si la inserción se realizó
      cout << "Se pudo realizar la insercion del 3\n";
   } else {                         // la inserción falla si ya existe la clave; multiset<T> permite claves duplicadas
      cout << "No se pudo realizar la insercion del 3\n";
   }
   cout << *info.first << " es la clave nodo\n";     // desreferenciar un set<int>::iterator devuelve un int
}
