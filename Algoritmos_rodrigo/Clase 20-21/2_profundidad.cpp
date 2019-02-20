// Este programa implementa la búsqueda en profundidad (iterativa) sobre una gráfica almacenada en listas de adyacencia, imprimiendo los vértices conforme son visitados
// Además de la información de la gráfica, este programa pide el índice del vértice inicial del recorrido
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void profundidad(int i, vector<int> adyacencia[], int v)
{  // invariante: lo marcamos como visitado al tiempo que lo imprimimos
   vector<bool> visitados(v, false);
   stack<int> pila;
   pila.push(i);                       // metemos en la pila al vértice inicial

   do {
      int actual = pila.top( );
      pila.pop( );
      if (visitados[actual]) {         // si ya lo imprimimos, lo ignoramos
         continue;
      }

      cout << actual << "\n";          // lo imprimimos
      visitados[actual] = true;        // lo marcamos
      for (int vecino : adyacencia[actual]) {         // iterativamente metemos a sus vecinos en la pila
         pila.push(vecino);                           // los vecinos listados primero se meterán primero en la pila, pero saldrán en orden contrario (primero el último vecino listado)
      }                                               // este orden es diferente al orden de profundidad recursiva, pero ambos son órdenes en profunidad válidos
   } while (!pila.empty( ));
}

int main( )
{
   int v, e;
   cin >> v >> e;

   vector<int> adyacencia[v];
   for (int i = 0; i < e; ++i) {
      int x, y;
      cin >> x >> y;
      adyacencia[x].push_back(y);
      adyacencia[y].push_back(x);
   }

   int inicial;
   cin >> inicial;
   profundidad(inicial, adyacencia, v);
}
