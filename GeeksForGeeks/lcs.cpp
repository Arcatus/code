#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct cordenada
{
  cordenada(int16_t a, int16_t b):x(a),y(b){};
  int16_t x;
  int16_t y;
};

int16_t max(int16_t a, int16_t b) 
{ 
    return (a > b)? a : b; 
}

int main() 
{ 

  int16_t i, j;

  char X[5000];
  char Y[5000];

  scanf("%s",X);
  scanf("%s",Y);
   
  int16_t m = strlen(X);
  int16_t n = strlen(Y);

  int16_t L[m+1][n+1];

  vector< cordenada* > tabla;

  for (i=0; i<=m; i++) { 
     for (j=0; j<=n; j++) { 
       if (i == 0 || j == 0) 
         L[i][j] = 0;
       else if (X[i-1] == Y[j-1]){
         L[i][j] = L[i-1][j-1] + 1; 
       }
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]); 
     } 
  }

  int16_t index = L[m][n];

  i = m, j = n; 
  while (i > 0 && j > 0) { 
      if (X[i-1] == Y[j-1]) { 
        tabla.push_back( new cordenada(i-1,j-1) );
        i--; j--; index--;
      }
      else if (L[i-1][j] > L[i][j-1])
         i--; 
      else
         j--; 
   } 

  sort(tabla.begin(),tabla.end(),
    [](cordenada* a, cordenada* b){ return a->x < b->x; } );

  printf("%d\n",L[m][n]);
  
  for (int16_t i = 0; i < tabla.size(); ++i ) {
      printf("%d %d\n",tabla[i]->x,tabla[i]->y);
  }
  
  return 0; 
}