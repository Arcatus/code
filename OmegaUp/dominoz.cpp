#include <cstdio>

typedef unsigned long long llu;
  
void multiply(llu F[2][2], llu M[2][2]); 
  
void power(llu F[2][2], llu n); 

llu fib(llu n)
{ 
  llu F[2][2] = {{1,1},{1,0}}; 
  if (n == 0) 
    return 0; 
  power(F, n-1); 
  return F[0][0]; 
} 

void power(llu F[2][2], llu n) 
{ 
  if( n == 0 || n == 1) 
      return; 
  llu M[2][2] = {{1,1},{1,0}}; 
  
  power(F, n/2); 
  multiply(F, F); 
  
  if (n%2 != 0) 
     multiply(F, M); 
} 
  
void multiply(llu F[2][2], llu M[2][2]) 
{ 

  llu x = ( ((( F[0][0]%1000000007)*M[0][0])%1000000007) + (((F[0][1]%1000000007)*M[1][0])%1000000007) )%1000000007;
  llu y = ( ((( F[0][0]%1000000007)*M[0][1])%1000000007) + (((F[0][1]%1000000007)*M[1][1])%1000000007) )%1000000007;
  llu z = ( ((( F[1][0]%1000000007)*M[0][0])%1000000007) + (((F[1][1]%1000000007)*M[1][0])%1000000007) )%1000000007;
  llu w = ( ((( F[1][0]%1000000007)*M[0][1])%1000000007) + (((F[1][1]%1000000007)*M[1][1])%1000000007) )%1000000007;
  
  F[0][0] = x; 
  F[0][1] = y; 
  F[1][0] = z; 
  F[1][1] = w; 
} 

int main() 
{ 
  llu n; 
  scanf("%llu",&n);
  printf("%llu\n", fib(n));
} 