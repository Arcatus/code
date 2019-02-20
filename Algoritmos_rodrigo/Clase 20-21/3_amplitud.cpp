// Este programa implementa la búsqueda en amplitud (iterativa) sobre una gráfica almacenada en listas de adyacencia, imprimiendo los vértices conforme son visitados
// Además de la información de la gráfica, este programa pide el índice del vértice inicial del recorrido
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void amplitud(int i, vector<int> adyacencia[], int v)
{  // invariante: lo marcamos como visitado al tiempo que lo imprimimos
   vector<bool> visitados(v, false);
   queue<int> cola;
   cola.push(i);                       // metemos en la cola al vértice inicial

   do {
      int actual = cola.front( );
      cola.pop( );
      if (visitados[actual]) {         // si ya lo imprimimos, lo ignoramos
         continue;
      }

      cout << actual << "\n";          // lo imprimimos
      visitados[actual] = true;        // lo marcamos
      for (int vecino : adyacencia[actual]) {         // iterativamente metemos a sus vecinos en la cola
         cola.push(vecino);                           // los vecinos listados primero se meterán primero en la cola, pero por ser una cola, saldrán justo en ese orden
      }
   } while (!cola.empty( ));
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
   amplitud(inicial, adyacencia, v);
}
