// Este programa implementa la b�squeda en profundidad (recursiva) sobre una gr�fica almacenada en listas de adyacencia, imprimiendo los v�rtices conforme son visitados
// Adem�s de la informaci�n de la gr�fica, este programa pide el �ndice del v�rtice inicial del recorrido
#include <iostream>
#include <vector>
using namespace std;

void profundidad(int i, vector<int> adyacencia[], vector<bool>& visitados)
{  // invariante: lo marcamos como visitado al tiempo que lo imprimimos
   if (visitados[i]) {              // si ya lo imprimimos, lo ignoramos
      return;
   }

   cout << i << "\n";               // lo imprimimos
   visitados[i] = true;             // lo marcamos
   for (int vecino : adyacencia[i]) {
      profundidad(vecino, adyacencia, visitados);     // recursivamente inspeccionamos a sus vecinos
   }                                                  // la recursi�n imprimir� primero los vecinos listados primero
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

   vector<bool> visitados(v, false);
   profundidad(inicial, adyacencia, visitados);
}
