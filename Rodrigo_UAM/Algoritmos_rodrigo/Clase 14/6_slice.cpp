// ejemplo de uso de la función list.slice( ), la cual sirve para concatenar y cortar listas
#include <algorithm>
#include <iostream>
#include <list>
using namespace std;

template<typename T>
void imprime(const list<T>& li)
{
   cout << "{ ";
   for (auto i = li.begin( ); i != li.end( ); ++i) {
      cout << *i << " ";
   }
   cout << "}\n";

   /* equivalente:
      for (const auto& v : li) {
         cout << v << " ";
      }
   } */
}

int main( )
{
   list<int> li;
   li.push_back(3);              // { 3 }
   li.push_back(1);              // { 3, 1 }
   li.push_back(7);              // { 3, 1, 7 }
   li.push_front(2);             // { 2, 3, 1, 7 }
   li.push_front(8);             // { 8, 2, 3, 1, 7 }
   li.pop_front( );              // { 2, 3, 1, 7 }
   li.push_back(5);              // { 2, 3, 1, 7, 5 };
   li.pop_back( );               // { 2, 3, 1, 7 };
   li.push_back(9);              // { 2, 3, 1, 7, 9 };
   li.push_back(6);              // { 2, 3, 1, 7, 9, 6 };
   imprime(li);
   cout << "\n";

   list<int> temp1 = { 0, 0, 0 };
   li.splice(li.end( ), temp1);     // pegar la lista temp1 al final de li, temp1 queda vacía y li se queda con todos los elementos
   imprime(temp1);                  // { }
   imprime(li);                     // { 2, 3, 1, 7, 9, 6, 0, 0, 0 };
   cout << "\n";

   list<int> temp2 = { -1, -1, -1 };
   li.splice(li.begin( ), temp2);   // pegar la lista temp2 al inicio de li, temp2 queda vacía y li se queda con todos los elementos
   imprime(temp2);                  // { }
   imprime(li);                     // { -1, -1, -1, 2, 3, 1, 7, 9, 6, 0, 0, 0 };
   cout << "\n";

   list<int> destino;
   auto buscar = find(li.begin( ), li.end( ), 7);              // buscar un 7 en la lista
   destino.splice(destino.end( ), li, buscar, li.end( ));      // transferir todos los elementos de li a destino a partir de la ubicación del 7
   imprime(destino);                // { 7, 9, 6, 0, 0, 0 }
   imprime(li);                     // { -1, -1, -1, 2, 3, 1 };
   cout << "\n";
}
