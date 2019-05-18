// Este programa implementa la lectura de la entrada para una gr�fica que ser� almacenada en una matriz de adyacencia
// Se asume que los primeros dos valores son el n�mero de v�rtices V y el n�mero de aristas E (donde los v�rtices est�n impl�citamente numerados a partir de 0)
// y que siguen E parejas de enteros que denotan las aristas (bidireccionales)
// Una matriz de adyacencia debe usarse cuando el n�mero de aristas de la gr�fica se espera que sea muy alto (gr�fica densa, del orden de V * V aristas)
#include <iostream>
using namespace std;

int main( )
{
   int v, e;
   cin >> v >> e;
                                       // vector<vector<bool>> adyacencia(v, vector<bool>(v, false));
   bool adyacencia[v][v] = { };        // una matriz de adyacencia almacena si un v�rtice est� conectado con otro;
   for (int i = 0; i < e; ++i) {       // una matriz cuadrada del n�mero de v�rtices por lado guarda los valores booleanos correspondientes (inicialmente llena de falso)
      int x, y;
      cin >> x >> y;                   // leemos los extremos de una arista
      adyacencia[x][y] = true;         // x es vecino de y
      adyacencia[y][x] = true;         // y es vecino de x
   }

   cout << "  \t";
   for (int i = 0; i < v; ++i) {
      cout << i << ":\t";
   }
   cout << "\n";
   for (int i = 0; i < v; ++i) {
      cout << i << ":\t";
      for (int j = 0; j < v; ++j) {
         cout << adyacencia[i][j] << " \t";
      }
      cout << "\n";
   }
}
