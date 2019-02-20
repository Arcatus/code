// este programa muestra la implementaci�n de las funciones push_heap, pop_heap y sort_heap; todas ya est�n implementadas en la biblioteca
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int* padre(int* ini, int* actual)
{
   return ini + (actual - ini - 1) / 2;         // mi �ndice i es la resta entre mi apuntador y el inicio del arreglo; el �ndice de mi padre es (i - 1) / 2
}

int* hijo_izq(int* ini, int* actual)
{
   return ini + (actual - ini) * 2 + 1;         // mi �ndice i es la resta entre mi apuntador y el inicio del arreglo; el �ndice de hijo izquierdo es i * 2 + 1
}

int* hijo_der(int* ini, int* actual)
{
   return ini + (actual - ini) * 2 + 2;         // mi �ndice i es la resta entre mi apuntador y el inicio del arreglo; el �ndice de hijo izquierdo es i * 2 + 2
}

void sube_nodo(int* ini, int* actual, int* fin)                   // el valor que est� subiendo es *actual
{
   while (actual != ini && *actual > *padre(ini, actual)) {       // mientras no llegue a la cima y simult�neamente sea mayor que su padre
      swap(*actual, *padre(ini, actual));                         // intercambia su valor con el de su padre
      actual = padre(ini, actual);                                // repite el proceso pero ahora desde el padre
   }
}

void baja_nodo(int* ini, int* actual, int* fin)                   // el valor que est� bajando es *actual
{
   int* elegido = actual;                                                     // elegido es el apuntador al mayor valor entre �l, su hijo izquierdo y su hijo derecho; comienza suponiendo que �l es el mayor valor
   if (hijo_izq(actual, ini) < fin && *hijo_izq(actual, ini) > *elegido) {    // si tiene hijo izquierdo (el apuntador calculado no se sale del arreglo) y el hijo es mayor que el elegido
      elegido = hijo_izq(actual, ini);                                        // entonces el elegido pasa a ser el hijo izquierdo
   }
   if (hijo_der(actual, ini) < fin && *hijo_der(actual, ini) > *elegido) {    // si tiene hijo derecho (el apuntador calculado no se sale del arreglo) y el hijo es mayor que el elegido
      elegido = hijo_der(actual, ini);                                        // entonces el elegido pasa a ser el hijo derecho
   }

   if (elegido != actual) {               // si el elegido no fue el nodo original sino que fue uno de sus hijos
      swap(*actual, *elegido);            // intercambiamos su valor con el del hijo elegido
      baja_nodo(ini, elegido, fin);       // repetimos el proceso bajando por el hijo elegido
   }
}

void push_heap(int* ini, int* fin)        // push_heap asume que todos los elementos menos el �ltimo ya son un mont�culo
{                                         // s�lo basta incorporar el �ltimo elemento al mont�culo
   sube_nodo(ini, fin - 1, fin);          // subimos el valor del �ltimo elemento hasta que quede en su lugar
}

void pop_heap(int* ini, int* fin)         // pop_heap asume que todos los elementos ya son un mont�culo
{
   std::swap(*ini, *(fin - 1));           // intercambiamos la cima con el �ltimo valor de la secuencia
   baja_nodo(ini, ini, fin - 1);          // bajamos el valor que qued� en la cima hasta que quede en su lugar, pasamos fin - 1 porque el �ltimo elemento del mont�culo
}                                         // acaba de quedar desincorporado y no queremos interactuar con �l durante la bajada

void make_heap(int* ini, int* fin)        // make_heap toma una secuencia de elementos y los acomoda en un mont�culo
{
   for (auto i = fin; i != ini; --i) {    // comenzando desde los pisos inferiores, toma cada uno de los nodos y realiza el ajuste hacia abajo
      baja_nodo(ini, i - 1, fin);         // el an�lisis de este algoritmo es complicado, pero es m�s r�pido que n llamadas a push_heap
   }                                      // toma tiempo ~n en lugar de ~n*log2(n)
}

void sort_heap(int* ini, int* fin)        // sort_heap asume que todos los elementos ya son un mont�culo
{
   for (auto i = fin; i != ini; --i) {    // como pop_heap va desincorporando la cima actual del mont�culo y lo deja como el �ltimo elemento del mont�culo,
      pop_heap(ini, i);                   // desincorporar todos los elementos deja la secuencia ordenada
   }
}

template<typename T>
void imprime(const vector<T>& v)
{
   cout << "{ ";
   for (int i = 0; i < v.size( ); ++i) {
      cout << v[i] << " ";
   }
   cout << "}\n";
}

int main( )
{
   vector<int> v1 = { 3, 1, 4, 1, 5, 9, 2, 7 };
   for (int i = 0; i < v1.size( ); ++i) {
      push_heap(v1.begin( ), v1.begin( ) + i + 1);
   }
   imprime(v1);
   std::cout << is_heap(v1.begin( ), v1.end( )) << "\n";       // is_heap tambi�n es parte de la biblioteca

   vector<int> v2 = { 3, 1, 4, 1, 5, 9, 2, 7 };
   make_heap(v2.begin( ), v2.end( ));
   imprime(v2);                                                // no necesariamente imprime lo mismo, pueden existir mont�culos v�lidos que se ven diferentes
   std::cout << is_heap(v1.begin( ), v1.end( )) << "\n";

   for (int i = v1.size( ); i > 0; --i) {
      pop_heap(v1.begin( ), v1.begin( ) + i);
   }
   imprime(v1);
   std::cout << is_sorted(v1.begin( ), v1.end( )) << "\n"      // is_sorted tambi�n es parte de la biblioteca

   sort_heap(v2.begin( ), v2.end( ));
   imprime(v2);
   std::cout << is_sorted(v2.begin( ), v2.end( )) << "\n";
}

