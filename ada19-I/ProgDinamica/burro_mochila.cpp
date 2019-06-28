#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <numeric>

/*
   Recurrencia del problema de la mochila

   int mochila(int i, int c) {
      if (i == n) {
         return 0;
      } else {
         int res = mochila(i + 1, c);
         if (c >= arr[i]) {
            res = std::max(res, mochila(i + 1, c - arr[i]) + arr[i]);
         }
         return res;
      }
   }
*/

int main( ) {
   int n;
   std::cin >> n;

   int arr[n];
   for (int i = 0; i < n; ++i) {
      std::cin >> arr[i];
   }
   int suma = std::accumulate(arr, arr + n, 0);
   int mitad = suma / 2;

   int memoria[n + 1][mitad + 1];
   for (int i = n; i >= 0; --i) {
      for (int c = 0; c <= mitad; ++c) {
         if (i == n) {
            memoria[i][c] = 0;
         } else {
            int res = memoria[i + 1][c];
            if (c >= arr[i]) {
               res = std::max(res, memoria[i + 1][c - arr[i]] + arr[i]);
            }
            memoria[i][c] = res;
         }
      }
   }

   int izq = memoria[0][mitad];
   int der = suma - izq;
   std::cout << std::abs(izq - der) << "\n";
}
