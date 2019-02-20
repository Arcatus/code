// Este programa implementa la lectura de la entrada para una gráfica que será almacenada en una matriz de adyacencia
// Se asume que los primeros dos valores son el número de vértices V y el número de aristas E (donde los vértices están implícitamente numerados a partir de 0)
// y que siguen E parejas de enteros que denotan las aristas (bidireccionales)
// Una matriz de adyacencia debe usarse cuando el número de aristas de la gráfica se espera que sea muy alto (gráfica densa, del orden de V * V aristas)
#include <iostream>
using namespace std;

int main( )
{
   int v, e;
   cin >> v >> e;
                                       // vector<vector<bool>> adyacencia(v, vector<bool>(v, false));
   bool adyacencia[v][v] = { };        // una matriz de adyacencia almacena si un vértice está conectado con otro;
   for (int i = 0; i < e; ++i) {       // una matriz cuadrada del número de vértices por lado guarda los valores booleanos correspondientes (inicialmente llena de falso)
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
