#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;

void radix_sort(const char** ini, const char** fin, int x)
{
   int n = fin - ini;
   if (n <= 1) {
      return;
   }

   /*if (n < k) {
      return sort(ini, fin, [&](const char* p1, const char* p2) {
         return strcmp(p1 + x, p2 + x) < 0;
      });
   }*/

   int cuentas[128] = { };
   for (int i = 0; i < n; ++i) {
      cuentas[ini[i][x]] += 1;
   }

   int inicios[128] = { };
   for (int i = 1; i < 128; ++i) {
      inicios[i] = inicios[i - 1] + cuentas[i - 1];
   }

   const char* temp[n];
   for (int i = 0; i < n; ++i) {
      temp[inicios[ini[i][x]]++] = ini[i];
   }

   for (int i = 1; i < 128; ++i) {
      radix_sort(&temp[0] + inicios[i] - cuentas[i], &temp[0] + inicios[i], x + 1);
   }
   for (int i = 0; i < n; ++i) {
      ini[i] = temp[i];
   }
}

int main( )
{
   const char* cadenas[] = {
      "abaaab",
      "gatito",
      "aabba",
      "gavilan",
      "aab",
      "gatitos",
      "",
      "bebe"
   };

   radix_sort(cadenas, cadenas + 8, 0);
   for (int i = 0; i < 8; ++i) {
      printf("%s\n", cadenas[i]);
   }
}
