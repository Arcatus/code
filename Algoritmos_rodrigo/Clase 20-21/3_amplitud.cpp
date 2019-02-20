// Este programa implementa la b�squeda en amplitud (iterativa) sobre una gr�fica almacenada en listas de adyacencia, imprimiendo los v�rtices conforme son visitados
// Adem�s de la informaci�n de la gr�fica, este programa pide el �ndice del v�rtice inicial del recorrido
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void amplitud(int i, vector<int> adyacencia[], int v)
{  // invariante: lo marcamos como visitado al tiempo que lo imprimimos
   vector<bool> visitados(v, false);
   queue<int> cola;
   cola.push(i);                       // metemos en la cola al v�rtice inicial

   do {
      int actual = cola.front( );
      cola.pop( );
      if (visitados[actual]) {         // si ya lo imprimimos, lo ignoramos
         continue;
      }

      cout << actual << "\n";          // lo imprimimos
      visitados[actual] = true;        // lo marcamos
      for (int vecino : adyacencia[actual]) {         // iterativamente metemos a sus vecinos en la cola
         cola.push(vecino);                           // los vecinos listados primero se meter�n primero en la cola, pero por ser una cola, saldr�n justo en ese orden
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
