//https://omegaup.com/arena/problem/Tri-Llenado#problems
#include <stdio.h>

int resuelve(int n) {               // asunción: n >= 0
   if (n == 0) {
      return 1;
   } else if (n == 1) {
      return 0;
   } else if (n == 2) {
      return 3;
   } else {

      int res = resuelve(2) * resuelve(n - 2);

      for (int i = 4; n - i >= 0; i += 2) // 6 - 4 = 2; -> 2 , 0
      {
         res += 2 * resuelve(n - i);
      }
      return res;
   }
}

int main( ) {
   int n;
   scanf("%d", &n);
   printf("%d\n", resuelve(n));
}
