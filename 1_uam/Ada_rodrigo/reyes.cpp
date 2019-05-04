// Problema 3 de http://academicos.azc.uam.mx/franz/dda/2006i/dda-c.html
#include <stdio.h>

int n;
int contador = 0;
int tablero[10 + 2][10 + 2] = { };

bool rey_valido(int i, int j) {
   for (int x = -1; x <= +1; ++x) {
      for (int y = -1; y <= +1; ++y) {
         if (tablero[i + x][j + y] == 1) {
            return false;
         }
      }
   }
   return true;
}

void genera(int i, int j, int k) {

   if (k == 0) {
      contador += 1;
      return;
   } else if (i == n + 1) {
      return;
   }

   if (j == n) {
      genera(i + 1, 1, k);
      if (rey_valido(i, j)) {
         tablero[i][j] = 1;
         genera(i + 1, 1, k - 1);
         tablero[i][j] = 0;
      }
   } else {
      genera(i, j + 1, k);
      if (rey_valido(i, j)) {
         tablero[i][j] = 1;
         genera(i, j + 1, k - 1);
         tablero[i][j] = 0;
      }
   }
}

int main( ) {
   int k;
   scanf("%d%d", &n, &k);
   genera(1, 1, k);
   printf("%d\n", contador);
}
