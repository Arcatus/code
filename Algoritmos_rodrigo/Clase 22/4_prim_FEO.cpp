// Este programa implementa el algoritmo de Prim sobre una gr�fica almacenada en listas de adyacencia.
// El algoritmo de Prim calcula un �rbol abarcador de costo m�nimo, el cual conecta todos los v�rtices de la gr�fica de modo que la suma de las aristas usadas se minimice.
// Este algoritmo funciona sin importar desde qu� vertice se comience la construcci�n del �rbol (el �rbol puede resultar diferente, pero tiene el mismo costo).
// El algoritmo de Prim mete en una cola de prioridad la informaci�n de las aristas que descubre conforme el �rbol crece y saca de la cola la informaci�n que corresponde a
// la arista m�s barata. Si poner la arista sacada crear�a un ciclo, entonces la ignora y saca la siguiente.

#include <algorithm>
#include <functional>
#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <tuple>              // generalizaci�n de pair
#include <vector>
using namespace std;

template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

vector<int> prim(int i, vector<pair<int, int>> adyacencia[], int v)
{
   vector<int> predecesores(v, -1);       // el predecesor de un v�rtice es el vecino al que nos conectamos para incorporarnos al �rbol; -1 �ndica que a�n no estamos en el �rbol
   min_heap<tuple<int, int, int>> cola;   // guardaremos tripletas (costo_arista, v�rtice, predecesor) en la cola, las cuales denotan una posible manera de incorporar un v�rtice al �rbol
   cola.push(make_tuple(0, i, i));        // de la cola ir� saliendo la tripleta con la arista m�s barata; como caso especial, el v�rtice inicial puede incorporarse a costo 0 por s� mismo

   do {
      auto datos = cola.top( );                    // datos es una tripleta (costo_arista, v�rtice, predecesor)
      cola.pop( );
      if (predecesores[get<1>(datos)] != -1) {     // si el v�rtice ya estaba incorporado al �rbol, lo ignoramos
         continue;
      }

      predecesores[get<1>(datos)] = get<2>(datos);       // si el v�rtice no estaba incorporado al �rbol, registramos que lo incorporamos usando el predecesor sugerido
      for (auto arista : adyacencia[get<1>(datos)]) {    // iterativamente inspeccionamos a sus vecinos
         cola.push(make_tuple(arista.first, arista.second, get<1>(datos)));   // nuestro vecino podr�a incorporarse con la arista que estamos viendo en este momento
      }                                                                       // y el predecesor ser�amos nosotros
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
