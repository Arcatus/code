#include <cstdio>
#include <cstring>
#include <algorithm>

char a[45000+1];
char b[45000+1];

int main( ) 
{
   scanf("%s",a);
   scanf("%s",b);

   int asize = strlen(a);
   int bsize = strlen(b);

   if (asize <= 1000 && bsize <= 1000) {
      int memoria[asize + 1][bsize + 1];

      for (int i = asize; i >= 0; --i) {
         for (int j = bsize; j >= 0; --j) {
            if (i == asize || j == bsize) {
               memoria[i][j] = 0;
            } else if (a[i] == b[j]) {
               memoria[i][j] = 1 + memoria[i + 1][j + 1];
            } else {
               if ( memoria[i][j + 1] > memoria[i + 1][j] )
               {
                  memoria[i][j] = memoria[i][j + 1];
               }
               else 
               {
                  memoria[i][j] = memoria[i + 1][j];
               }
            }
         }
      }
      printf("%d\n",memoria[0][0]);

      int i = 0, j = 0;
      while (i < asize && j < bsize ) 
      {
         if (a[i] == b[j]) {
            printf("%d %d\n",i++,j++);
         } else if (memoria[i][j] == memoria[i][j + 1]) {
            ++j;
         } else if (memoria[i][j] == memoria[i + 1][j]) {
            ++i;
         }
      }

   } else {
      int memoria[2][bsize + 1];
      int* actual = memoria[0];
      int* previa = memoria[1];

      for (int i = asize; i >= 0; --i, std::swap(actual, previa)) {
         for (int j = bsize; j >= 0; --j) {
            if (i == asize || j == bsize ) {
               actual[j] = 0;
            } else if (a[i] == b[j]) {
               actual[j] = 1 + previa[j + 1];
            } else {
               actual[j] = std::max(actual[j + 1], previa[j]);
            }
         }
      }
      printf("%d\n",previa[0]);
   }
   return 0;
}