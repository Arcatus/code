// Este programa implementa el algoritmo de Dijkstra sobre una gráfica almacenada en listas de adyacencia
// El algoritmo de Dijkstra calcula la distancia más corta de un origen hacia el resto de los vértices pero funciona cuando las aristas tienen costos no unitarios y no negativos.
// Para cada arista, se deben proporcionar tres enteros: los extremos de la arista así como el costo de la misma
// Además de la información de la gráfica, este programa pide el índice del vértice inicial del recorrido
#include <functional>
#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

vector<int> dijkstra(int i, vector<pair<int, int>> adyacencia[], int v)
{
   vector<int> distancias(v, INT_MAX);    // distancia a los vértices; para vértices que no hemos alcanzado diremos que su distancia es infinita
   min_heap<pair<int, int>> cola;         // guardaremos parejas (distancia, vértice) en la cola, las cuales denotan una posible distancia para el vértice dado
   cola.push({ 0, i });                   // de la cola irá saliendo la pareja con la menor distancia; metemos que el vértice inicial está a distancia 0

   do {
      auto datos = cola.top( );                      // datos es una pareja (distancia, vértice)
      cola.pop( );
      if (distancias[datos.second] != INT_MAX) {     // si ya habíamos llegado a este vértice antes, lo ignoramos (la primera vez llegamos con menos distancia)
         continue;
      }

      distancias[datos.second] = datos.first;        // si es la primera vez que llegamos a este vértice, entonces quitamos el INT_MAX y registramos su distancia real
      for (auto arista : adyacencia[datos.second]) {                 // iterativamente inspeccionamos a sus vecinos
         cola.push({ arista.first + datos.first, arista.second });   // si nosotros estamos a cierta distancia, nuestro vecino está a esa distancia + el costo de la arista
      }
   } while (!cola.empty( ));

   return distancias;
}

int main( )
{
   int v, e;
   cin >> v >> e;

   vector<pair<int, int>> adyacencia[v];
   for (int i = 0; i < e; ++i) {
      int x, y, c;
      cin >> x >> y >> c;
      adyacencia[x].push_back({ c, y });
      adyacencia[y].push_back({ c, x });
   }

   int inicial;
   cin >> inicial;

   auto distancias = dijkstra(inicial, adyacencia, v);
   for (int i = 0; i < v; ++i) {
      cout << i << ": " << distancias[i] << "\n";
   }
}
