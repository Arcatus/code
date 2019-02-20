// ejemplo de implementación de una lista doblemente enlazada, implementada como una lista circular con un nodo ficticio que denota el fin
// no está pensada en ser usada en código real (tiene fugas de memoria, por ejemplo); siempre prefieran usar <list> de C++
#include <iostream>
using namespace std;

template<typename T>
struct nodo {
   T valor;
   nodo* ant = this;    // por omisión, el nodo anterior a mí soy yo mismo
   nodo* sig = this;    // por omisión, el nodo siguiente a mí soy yo mismo
};                      // el significado de this lo verán en la UEA "Programación Orientada a Objetos"

template<typename T>
struct mi_list {
   nodo<T>* ficticio = new nodo<T>;                // el nodo ficticio denota el fin, quien inicialmente es su propio nodo siguiente y nodo anterior

   void insert(nodo<T>* punto, const T& valor)     // el punto de inserción quedará adelante del nuevo nodo
   {
      auto nuevo = new nodo<T>;
      nuevo->valor = valor;            // copiamos el valor al nuevo nodo
      nuevo->sig = punto;              // el siguiente al nuevo nodo es el punto de inserción
      nuevo->ant = punto->ant;         // el anterior al nuevo nodo es el actual nodo anterior del punto de inserción
      punto->ant->sig = nuevo;         // para el nodo de atrás del punto de inserción, el siguiente ahora es el nuevo nodo
      punto->ant = nuevo;              // para el punto de inserción, el anterior ahora es el nuevo nodo
   }

   void erase(nodo<T>* punto)
   {                                   // desconectamos el nodo
      punto->ant->sig = punto->sig;    // el nodo siguiente se volverá el siguiente del nodo anterior
      punto->sig->ant = punto->ant;    // el nodo anteror se volverá el anterior del nodo siguiente
      delete punto;                    // como los nodos los pedimos con new, liberamos la memoria del nodo que acabamos de desconectar
   }

   nodo<T>* begin( )
   {
      return ficticio->sig;            // en la lista circular, el nodo siguiente del fin es el inicio
   }

   nodo<T>* end( )
   {
      return ficticio;
   }

   void push_front(const T& valor)
   {
      insert(begin( ), valor);
   }

   void push_back(const T& valor)
   {
      insert(end( ), valor);
   }

   void pop_front( )
   {
      erase(begin( ));
   }

   void pop_back( )
   {
      erase(end( )->ant);
   }
};

template<typename T>
nodo<T>* next(nodo<T>* nodo, int k = 1)         // si no se indica el valor de k al llamar a la función, se asume que vale k = 1
{
   for (int i = 0; i < k; ++i) {
      nodo = nodo->sig;
   }
   return nodo;
}

template<typename T>
nodo<T>* prev(nodo<T>* nodo, int k = 1)         // si no se indica el valor de k al llamar a la función, se asume que vale k = 1
{
   for (int i = 0; i < k; ++i) {
      nodo = nodo->prev;
   }
   return nodo;
}

template<typename T>
void imprime(mi_list<T>& li)
{
   for (auto i = li.begin( ); i != li.end( ); i = next(i)) {         // con list<T> pueden usar ++i, pero no implementé esa sintaxis en este programa
      cout << i->valor << " ";                                       // con list<T> pueden usar *i, pero no implementé esa sintaxis en este programa
   }
   cout << "\n";
}

int main( )
{
   mi_list<int> li;                    // aunque funciona, noten que aún no está implementada toda la sintaxis ni todas las funciones que ofrece list<T> y
   li.push_back(3);                    // de todos modos el código ya es bastante largo, siempre revisen la biblioteca para ver si lo que necesitan ya está disponible
   li.push_back(1);
   li.push_back(4);
   li.push_front(5);
   li.push_front(0);
   imprime(li);
   li.erase(next(li.begin( ), 2));
   imprime(li);
   li.pop_front( );
   li.pop_back( );
   imprime(li);
}
