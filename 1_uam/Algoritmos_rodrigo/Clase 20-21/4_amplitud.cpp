// Este programa implementa la búsqueda en amplitud (iterativa) sobre una gráfica almacenada en listas de adyacencia, imprimiendo los vértices conforme son visitados
// Además de la información de la gráfica, este programa pide el índice del vértice inicial del recorrido
// Esta versión de búsqueda en amplitud marca los vértices como visitados de manera anticipada
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void amplitud(int i, vector<int> adyacencia[], int v)
{  // invariante: lo marcamos en cuanto lo metemos a la cola; esto es correcto, pues los vértices se imprimirán justo en el orden en el que se meten a la cola
   vector<bool> visitados(v, false);
   queue<int> cola;
   cola.push(i);                       // metemos en la cola al vértice inicial
   visitados[i] = true;                // lo marcamos

   do {
      int actual = cola.front( );
      cola.pop( );
      cout << actual << "\n";          // como un elemento que entra a la cola ya está marcado, cuando sale lo imprimimos sin preguntar si estaba marcado (eso ya sabemos que es cierto)

      for (int vecino : adyacencia[actual]) {      // iterativamente inspeccionamos a sus vecinos
         if (!visitados[vecino]) {                 // si no está marcado
            visitados[vecino] = true;              // lo marcamos
            cola.push(vecino);                     // lo metemos a la cola
         }
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
