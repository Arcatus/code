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
      costo_global = min(costo_global, costo_local);
      return;
   }

   for (int j = i; j < n; ++j) {

      int arista = (i == 0 ? 0 : matriz[arr[i - 1]][arr[j]]);      

      swap(arr[i], arr[j]);      
      costo_local += arista;
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