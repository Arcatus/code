#include <iostream>
#include <string>

/*
   Relación recursiva:
   
   int lcs(int i, int j)
   {
      if (i == a.size( ) || j == b.size( )) {
         return 0;
      }
      
      if (a[i] == b[j]) {
         return 1 + lcs(i + 1, j + 1);     
      }
      
      return std::max(lcs(i + 1, j), lcs(i, j + 1));
   }
*/

int main( )
{
   std::string a, b;
   std::cin >> a >> b;
   
   int tabla[a.size( ) + 1][b.size( ) + 1];
   
   for (int i = a.size( ); i >= 0; --i) {
      for (int j = b.size( ); j >= 0; --j) {
         if (i == a.size( ) || j == b.size( )) {
            tabla[i][j] = 0;
         }
         else if (a[i] == b[j]) {
            tabla[i][j] = 1 + tabla[i + 1][j + 1];     
         }
         else {
            tabla[i][j] = std::max(tabla[i][j + 1], tabla[i + 1][j]);
         }
      }
   }
   
   std::cout << tabla[0][0] << '\n';
   
   int i = 0;
   int j = 0;
   
   while (i != a.size( ) && j != b.size( )) {
      if (a[i] == b[j]) {
         std::cout << a[i];
      
         ++i;
         ++j;
      }
      else if (tabla[i][j] == tabla[i][j + 1]) {
         ++j;
      }
      else if (tabla[i][j] == tabla[i + 1][j]) {
         ++i;     
      }
   }
}