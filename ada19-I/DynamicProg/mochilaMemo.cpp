// El problema de la mochila (recursión con memorización)
#include <algorithm>
#include <stdio.h>
using namespace std;

int n;
int objetos[40];
int memoria[40 + 1][1000 + 1];

int resuelve(int i, int c) {
   if (memoria[i][c] == -1) {
      if (i == n) {
         memoria[i][c] = 0;
      } else {
         int res = resuelve(i + 1, c);
         if (objetos[i] <= c) {
            res = max(res, objetos[i] + resuelve(i + 1, c - objetos[i]));
         }
         memoria[i][c] = res;
      }
   }
   return memoria[i][c];
}

int main( ) {
   int capacidad;
   scanf("%d%d", &n, &capacidad);
   for (int i = 0; i < n; ++i) {
      scanf("%d", &objetos[i]);
   }

   for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= capacidad; ++j) {
         memoria[i][j] = -1;
      }
   }
   printf("%d\n", resuelve(0, capacidad));
}
