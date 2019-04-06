// programa que ejemplifica deque, que es una doble cola (permite agregar y quitar elementos eficientemente tanto al inicio como al final de la secuencia)
#include <algorithm>
#include <deque>
#include <iostream>
using namespace std;

void imprime(const deque<int>& d)            // paso por referencia a const; si pasamos por valor estaríamos haciendo una copia del deque completo y realmente no necesitamos hacer eso
{                                            // pasamos por referencia para evitar la copia y por const para indicar que no necesitamos modificarlo, solo leerlo
   cout << "{ ";
   for (int i = 0; i < d.size( ); ++i) {
      cout << d[i] << " ";
   }
   cout << "} \n";
}

int main( )
{
   deque<int> d;
   d.push_back(5);
   imprime(d);
   d.push_back(3);
   imprime(d);
   d.push_back(1);
   imprime(d);
   d.push_front(6);
   imprime(d);

   sort(d.begin( ), d.end( ));         // en deque NO deben usar &d[0] y &d[d.size( ) - 1] como el inicio y el fin, aunque compile: su programa tronará
   imprime(d);                         // los iteradores de vector y string son compatibles con apuntadores, los de deque no lo son
}                                      // en general, prefieran usar siempre .begin( ) y .end( )
