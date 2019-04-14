// https://omegaup.com/arena/problem/caracteres_subcadenas/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( )
{
   const char* s = "a@badzdabg@h!b";
   int n = strlen(s);

   int cuentas[128] = { };
   for (int i = 0; i < n; ++i) {
      cuentas[s[i]] += 1;
   }

   int* filas[128];
   for (int i = 0; i < 128; ++i) {
      filas[i] = new int[cuentas[i]];
   }

   int pos_lista[128] = { };
   for (int i = 0; i < n; ++i) {
      filas[s[i]][pos_lista[s[i]]++] = i;
   }

   for (int i = 0; i < 128; ++i) {
      printf("%c: ", i);
      for (int j = 0; j < cuentas[i]; ++j) {
         printf("%d ", filas[i][j]);
      }
      printf("\n");
   }
}
