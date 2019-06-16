// El problema de la mochila (programación dinámica): todas las variables dentro de main
#include <algorithm>
#include <stdio.h>
using namespace std;

/*int resuelve(int i, int c) {
   if (i == n) {
      return 0;
   } else {
      int res = resuelve(i + 1, c);
      if (objetos[i] <= c) {
         res = max(res, objetos[i] + resuelve(i + 1, c - objetos[i]));
      }
      return res;
   }
}*/

int main( ) {
   int n, capacidad;
   scanf("%d%d", &n, &capacidad);

   int objetos[n];
   for (int i = 0; i < n; ++i) {
      scanf("%d", &objetos[i]);
   }

   int memoria[n + 1][capacidad + 1];
   for (int i = n; i >= 0; --i) {
      for (int c = 0; c <= capacidad; ++c) {
         if (i == n) {
            memoria[i][c] = 0;
         } else {
            int res = memoria[i + 1][c];
            if (objetos[i] <= c) {
               res = max(res, objetos[i] + memoria[i + 1][c - objetos[i]]);
            }
            memoria[i][c] = res;
         }
      }
   }

   printf("%d\n", memoria[0][capacidad]);
}
