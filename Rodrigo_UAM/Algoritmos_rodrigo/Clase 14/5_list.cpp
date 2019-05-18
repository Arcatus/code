// ejemplo de uso de list de C++, la cual implementa una lista doblemente enlazada
#include <algorithm>
#include <iostream>
#include <iterator>        // next(...), advance(...)
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

   auto iter = next(li.begin( ), 2);       // calcular el iterador que está dos posiciones adelante de .begin( ) mediante saltos sucesivos
   li.erase(iter);               // { 2, 3, X, 7, 9, 6};
   imprime(li);                  // eliminar un elemento de enmedio es muy rápido en list, pero primero hay que ubicarlo
}
