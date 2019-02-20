// decidir si un número es primo o no (más rápido)
#include <stdio.h>
#include <math.h>

int primo(int n)
{
   if (n == 1) {
      return 0;
   } else if (n % 2 == 0) {
      return n == 2;
   }

   int i, r = sqrt(n);
   for (i = 3; i <= r; i += 2) {
      if (n % i == 0) {
         return 0;
      }
   }

   return 1;
}

int main( )
{
   int n;
   scanf("%d", &n);              // probar con n = 982451653, que es primo
   printf("%d", primo(n));

   return 0;
}
