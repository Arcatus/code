#include <stdio.h>

char buffer[10 + 1];

void genera(int n) {
   if (n == 0) {
      printf("%s\n", buffer);
      return;
   }
   buffer[n - 1] = '0';
   genera(n - 1);
   buffer[n - 1] = '1';
   genera(n - 1);
}

int main( ) {
   int n;
   scanf("%d", &n);        
   genera(n);
}