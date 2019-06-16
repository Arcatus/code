#include <stdio.h>
#include <iostream>

using namespace std;

int n;
int p[1000010];

int arbitraryInit;

int comparer;

void compute_prime_table() /* with Sieve of Eratosthenes */
{
  int i,j;

  p[0] = p[1] = 0;
  for (i=2; i<=1000000; i++) p[i]=1; /* initialization */
  for (i=2; i<=1000;) /* for all primes up to 1000 */
    {
      for (j=i+i; j<=1000000; j+=i) p[j]=0; /* delete all multiples of i */
      for (i++; !p[i]; i++); /* find next prime */ 
    }
}

int solve_case()
{
  int i,j;

  for (i=0, j=n-3; i<=j; i++,j--) {
    if (p[i] && p[j]) break;
  }
  printf("%d %d\n",i,j);
  return 0;
}

int main()
{
  
  compute_prime_table();
  int c;
  scanf("%d",&c);

  for (int i=0;i<c;++i)
  {
      scanf("%d\n",&n);
      solve_case();
  }
  return 0;
}