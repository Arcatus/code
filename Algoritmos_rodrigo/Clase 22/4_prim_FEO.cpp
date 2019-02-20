// Este programa implementa el algoritmo de Prim sobre una gráfica almacenada en listas de adyacencia.
// El algoritmo de Prim calcula un árbol abarcador de costo mínimo, el cual conecta todos los vértices de la gráfica de modo que la suma de las aristas usadas se minimice.
// Este algoritmo funciona sin importar desde qué vertice se comience la construcción del árbol (el árbol puede resultar diferente, pero tiene el mismo costo).
// El algoritmo de Prim mete en una cola de prioridad la información de las aristas que descubre conforme el árbol crece y saca de la cola la información que corresponde a
// la arista más barata. Si poner la arista sacada crearía un ciclo, entonces la ignora y saca la siguiente.

#include <algorithm>
#include <functional>
#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <tuple>              // generalización de pair
#include <vector>
using namespace std;

template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

vector<int> prim(int i, vector<pair<int, int>> adyacencia[], int v)
{
   vector<int> predecesores(v, -1);       // el predecesor de un vértice es el vecino al que nos conectamos para incorporarnos al árbol; -1 índica que aún no estamos en el árbol
   min_heap<tuple<int, int, int>> cola;   // guardaremos tripletas (costo_arista, vértice, predecesor) en la cola, las cuales denotan una posible manera de incorporar un vértice al árbol
   cola.push(make_tuple(0, i, i));        // de la cola irá saliendo la tripleta con la arista más barata; como caso especial, el vértice inicial puede incorporarse a costo 0 por sí mismo

   do {
      auto datos = cola.top( );                    // datos es una tripleta (costo_arista, vértice, predecesor)
      cola.pop( );
      if (predecesores[get<1>(datos)] != -1) {     // si el vértice ya estaba incorporado al árbol, lo ignoramos
         continue;
      }

      predecesores[get<1>(datos)] = get<2>(datos);       // si el vértice no estaba incorporado al árbol, registramos que lo incorporamos usando el predecesor sugerido
      for (auto arista : adyacencia[get<1>(datos)]) {    // iterativamente inspeccionamos a sus vecinos
         cola.push(make_tuple(arista.first, arista.second, get<1>(datos)));   // nuestro vecino podría incorporarse con la arista que estamos viendo en este momento
      }                                                                       // y el predecesor seríamos nosotros
   } while (!cola.empty( ));

   return predecesores;
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

   auto predecesores = prim(inicial, adyacencia, v);
   for (int i = 0; i < v; ++i) {
      cout << i << ": se conecta con " << predecesores[i] << "\n";
   }

   int costo = 0;
   for (int i = 0; i < v; ++i) {
      costo += (i == inicial ? 0 : find_if(adyacencia[i].begin( ), adyacencia[i].end( ), [&](const pair<int, int>& p) {
         return p.second == predecesores[i];
      })->first);
   }
   cout << "El costo total del arbol es " << costo << "\n";
}
