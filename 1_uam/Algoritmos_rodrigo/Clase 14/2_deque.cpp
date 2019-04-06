// ejemplo de implementaci�n de una doble cola que usa la estrategia circular
// no est� pensada en ser usada en c�digo real (tiene fugas de memoria, por ejemplo); siempre prefieran usar <deque> de C++
#include <iostream>
using namespace std;

template<typename T>
struct mi_deque {
   T* mem = new T[1000];                     // bloque de memoria
   int tam = 0;                              // n�mero de elementos guardados
   int cap = 1000;                           // capacidad del bloque
   int ini = 0, fin = 0;                     // inicio y fin de la cola: por simplicidad, usaremos �ndices sobre mem en lugar de apuntadores sobre mem

   // declarar funciones dentro de un struct habilita la sintaxis .funcion( ) y las variables hacen referencia impl�citamente a los miembros del struct

   int size( )
   {
      return tam;
   }

   int capacity( )
   {
      return cap;
   }

   T& front( )
   {
      return mem[ini];                       // ini es el �ndice del primer elemento
   }

   T& back( )
   {
      return mem[(fin - 1 + cap) % cap];     // el �ltimo elemento est� en fin - 1, pero ajustamos para implementar la estrategia circular
   }

   void push_front(const T& v)
   {
      ini = (ini - 1 + cap) % cap;           // retrocedemos ini, pero ajustamos para implementar la estrategia circular
      mem[ini] = v;                          // escribimos en ini
      tam += 1;                              // reportamos que el tama�o aument�
   }

   void push_back(const T& v)
   {
      mem[fin] = v;                          // escribimos en fin
      fin = (fin + 1) % cap;                 // avanzamos fin, pero ajustamos para implementar la estrategia circular
      tam += 1;                              // reportamos que el tama�o aument�
   }

   void pop_front( )
   {
      ini = (ini + 1) % cap;                 // avanzamos ini, pero ajustamos para implementar la estrategia circular
      tam -= 1;                              // reportamos que el tama�o disminuy�
   }

   void pop_back( )
   {
      fin = (fin - 1 + cap) % cap;           // retrocedemos fin, pero ajustamos para implementar la estrategia circular
      tam -= 1;                              // reportamos que el tama�o disminuy�
   }

   T& operator[](int i)                      // acceder al i-�simo elemento
   {
      return mem[(ini + i) % cap];           // devolvemos mem[ini + 1] pero ajustamos para implementar la estrategia circular
   }
};

template<typename T>
void imprime(mi_deque<T>& d)
{
   cout << "{ ";
   for (int i = 0; i < d.size( ); ++i) {
      cout << d[i] << " ";
   }
   cout << "}\n";
}

int main( )
{
   mi_deque<int> d;
   d.push_back(3);
   d.push_back(1);
   d.push_back(8);
   imprime(d);
   d.push_front(4);
   imprime(d);
   d.pop_back( );
   imprime(d);
   d.pop_front( );
   imprime(d);
}
