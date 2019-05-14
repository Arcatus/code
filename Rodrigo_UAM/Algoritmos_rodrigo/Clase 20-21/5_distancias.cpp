// Este programa implementa la búsqueda en amplitud sobre una gráfica almacenada en listas de adyacencia para calcular las distancias mínimas de un origen al resto de los vértices
// Además de la información de la gráfica, este programa pide el índice del vértice inicial del recorrido
// Las aristas no tienen costo: se asume que son de costo unitario
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> calcula_distancias(int i, vector<int> adyacencia[], int v)
{
   vector<int> distancias(v, -1);        // para vértices que no han sido encontrados, diremos que su distancia es -1 del origen (lo cual claramente es imposible)
   queue<int> cola;
   cola.push(i);                          // metemos en la cola al vértice inicial
   distancias[i] = 0;                     // y decimos que su distancia es la 0

   do {
      int actual = cola.front( );
      cola.pop( );

      for (int vecino : adyacencia[actual]) {               // iterativamente inspeccionamos a sus vecinos
         if (distancias[vecino] == -1) {                    // si aún no habíamos visto ese vértice, su distancia es -1
            distancias[vecino] = distancias[actual] + 1;    // en ese caso, su distancia es uno más que la distancia que nosotros tenemos del origen
            cola.push(vecino);                              // y lo metemos a la cola
         }
      }
   } while (!cola.empty( ));

   return distancias;
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
   auto distancias = calcula_distancias(inicial, adyacencia, v);

   for (int i = 0; i < v; ++i) {                         // imprimimos las distancias
      cout << i << ": " << distancias[i] << "\n";        // vértices inalcanzables seguirán teniendo -1 como distancia
   }
}
