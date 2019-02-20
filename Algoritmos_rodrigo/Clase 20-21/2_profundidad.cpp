// Este programa implementa la b�squeda en profundidad (iterativa) sobre una gr�fica almacenada en listas de adyacencia, imprimiendo los v�rtices conforme son visitados
// Adem�s de la informaci�n de la gr�fica, este programa pide el �ndice del v�rtice inicial del recorrido
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void profundidad(int i, vector<int> adyacencia[], int v)
{  // invariante: lo marcamos como visitado al tiempo que lo imprimimos
   vector<bool> visitados(v, false);
   stack<int> pila;
   pila.push(i);                       // metemos en la pila al v�rtice inicial

   do {
      int actual = pila.top( );
      pila.pop( );
      if (visitados[actual]) {         // si ya lo imprimimos, lo ignoramos
         continue;
      }

      cout << actual << "\n";          // lo imprimimos
      visitados[actual] = true;        // lo marcamos
      for (int vecino : adyacencia[actual]) {         // iterativamente metemos a sus vecinos en la pila
         pila.push(vecino);                           // los vecinos listados primero se meter�n primero en la pila, pero saldr�n en orden contrario (primero el �ltimo vecino listado)
      }                                               // este orden es diferente al orden de profundidad recursiva, pero ambos son �rdenes en profunidad v�lidos
   } while (!pila.empty( ));
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
   profundidad(inicial, adyacencia, v);
}
