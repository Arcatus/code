#include <cstdio>
#include <cstring>
#include <algorithm>

char a[5000+1];
char b[5000+1];

int main( ) 
{
   scanf("%s",a);
   scanf("%s",b);

   int asize = strlen(a);
   int bsize = strlen(b);
   
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
   return 0;
}