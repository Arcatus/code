// Este programa implementa la lectura de la entrada para una gr�fica que ser� almacenada en un listas de adyacencia
// Se asume que los primeros dos valores son el n�mero de v�rtices V y el n�mero de aristas E (donde los v�rtices est�n impl�citamente numerados a partir de 0)
// y que siguen E parejas de enteros que denotan las aristas (bidireccionales)
// Las listas de adyacencia debe usarse cuando el n�mero de aristas de la gr�fica se espera que sea muy bajo (gr�fica dispersa, del orden de V aristas)
#include <iostream>
#include <vector>
using namespace std;

int main( )
{
   int v, e;
   cin >> v >> e;

   vector<int> adyacencia[v];          // una torre de vectores de enteros; el i-�simo vector guarda qui�nes son los vecinos del v�rtice i
   for (int i = 0; i < e; ++i) {       // una lista de adyacencia NO tiene que ser una lista enlazada; basta con que use memoria proporcional a los vecinos que le metimos, por lo que podemos usar vector
      int x, y;
      cin >> x >> y;                   // leemos los extremos de una arista
      adyacencia[x].push_back(y);      // agregamos y en la lista de vecinos de x
      adyacencia[y].push_back(x);      // agregamos x en la lista de vecinos de y
   }

   for (int i = 0; i < v; ++i) {
      cout << i << ": {";
      for (int v : adyacencia[i]) {
         cout << " " << v;
      }
      cout << " }\n";
   }
}
