// Este programa implementa la b�squeda en amplitud sobre una gr�fica almacenada en listas de adyacencia para calcular las distancias m�nimas de un origen al resto de los v�rtices
// Adem�s de la informaci�n de la gr�fica, este programa pide el �ndice del v�rtice inicial del recorrido
// Las aristas no tienen costo: se asume que son de costo unitario
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> calcula_distancias(int i, vector<int> adyacencia[], int v)
{
   vector<int> distancias(v, -1);        // para v�rtices que no han sido encontrados, diremos que su distancia es -1 del origen (lo cual claramente es imposible)
   queue<int> cola;
   cola.push(i);                          // metemos en la cola al v�rtice inicial
   distancias[i] = 0;                     // y decimos que su distancia es la 0

   do {
      int actual = cola.front( );
      cola.pop( );

      for (int vecino : adyacencia[actual]) {               // iterativamente inspeccionamos a sus vecinos
         if (distancias[vecino] == -1) {                    // si a�n no hab�amos visto ese v�rtice, su distancia es -1
            distancias[vecino] = distancias[actual] + 1;    // en ese caso, su distancia es uno m�s que la distancia que nosotros tenemos del origen
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
      cout << i << ": " << distancias[i] << "\n";        // v�rtices inalcanzables seguir�n teniendo -1 como distancia
   }
}
