#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

int n;
int arr[15];
int matriz[15][15];
int costo_global = INT_MAX, costo_local = 0;

void genera(int i) {
   if (i == n) {
      //actualizamos el costo global en caso de que el costo local sea menor
      //cerr << costo_local << '\n';
      costo_global = min(costo_global, costo_local);
      return;
   }

   for (int j = i; j < n; ++j) {
      //inicio sin costo sin importar el vertice todos tienen su inicio 0
      //Despues se calcula a partir de la matriz
      int arista = (i == 0 ? 0 : matriz[arr[i - 1]][arr[j]]);

      //cerr << "tomando de la matriz: " << arr[i-1] << " " << arr[j] << '\n';

      swap(arr[i], arr[j]);
      //hacemos backtrack en el costo local
      costo_local += arista;
      //hacemos prunning para optimizar el arbol recursivo
      //genera(i + 1);
      if ( costo_local < costo_global ) {
         genera(i + 1);
      }
      costo_local -= arista;
      swap(arr[i], arr[j]);
   }
}

int main( ) {
   ios::sync_with_stdio(false);
   cin.tie(0); 

   cin >> n;
   //inicializamos el arreglo que permutaremos
   for (int i = 0; i < n; ++i) {
      arr[i] = i;
   }
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         cin >> matriz[i][j];
      }
   }
   genera(0);
   cout << costo_global << "\n";

   return 0;
}