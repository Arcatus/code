// Este programa implementa la b�squeda en amplitud (iterativa) sobre una gr�fica almacenada en listas de adyacencia, imprimiendo los v�rtices conforme son visitados
// Adem�s de la informaci�n de la gr�fica, este programa pide el �ndice del v�rtice inicial del recorrido
// Esta versi�n de b�squeda en amplitud marca los v�rtices como visitados de manera anticipada
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void amplitud(int i, vector<int> adyacencia[], int v)
{  // invariante: lo marcamos en cuanto lo metemos a la cola; esto es correcto, pues los v�rtices se imprimir�n justo en el orden en el que se meten a la cola
   vector<bool> visitados(v, false);
   queue<int> cola;
   cola.push(i);                       // metemos en la cola al v�rtice inicial
   visitados[i] = true;                // lo marcamos

   do {
      int actual = cola.front( );
      cola.pop( );
      cout << actual << "\n";          // como un elemento que entra a la cola ya est� marcado, cuando sale lo imprimimos sin preguntar si estaba marcado (eso ya sabemos que es cierto)

      for (int vecino : adyacencia[actual]) {      // iterativamente inspeccionamos a sus vecinos
         if (!visitados[vecino]) {                 // si no est� marcado
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
