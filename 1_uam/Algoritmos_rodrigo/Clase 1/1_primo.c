// decidir si un número es primo o no
#include <stdio.h>

int primo(int n)
{
   if (n == 1) {
      return 0;
   }

   int i;
   for (i = 2; i < n; ++i) {
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
