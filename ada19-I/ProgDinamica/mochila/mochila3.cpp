// El problema de la mochila (backtracking): parámetros explícitos y ganancias como valores de retorno
#include <algorithm>
#include <stdio.h>
using namespace std;

int n;
int objetos[40];

int resuelve(int i, int c) {
   if (i == n) {
      return 0;
   }

   int res = resuelve(i + 1, c);
   if (objetos[i] <= c) {
      res = max(res, objetos[i] + resuelve(i + 1, c - objetos[i]));
   }
   return res;
}

int main( ) {
   int capacidad;
   scanf("%d%d", &n, &capacidad);
   for (int i = 0; i < n; ++i) {
      scanf("%d", &objetos[i]);
   }

   printf("%d\n", resuelve(0, capacidad));
}
