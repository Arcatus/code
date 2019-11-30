#include <cstdio>
#include <cmath>

int n;
bool p[5000001];

void compute_prime_table(int k = 5000001)
{
    int i,j;
    p[0] = p[1] = false;
    for (i=2; i<=k; i++) p[i]=true;
    for (i=2; i<=sqrt(k);)
    {
        for (j=i+i; j<=k; j+=i) p[j]=false;
        for (i++; !p[i]; i++);
    }
}

void solve_case()
{
  int i,j;

  for (i=3, j=n-3; i<=j; i++,j--) {
    if (p[i] && p[j]) break;
  }
  printf("%d %d\n",i,j);
}

int main()
{
  compute_prime_table();
  
  while(scanf("%d",&n), n != 0)
  {
      if (n == 4)
      {
        printf("2 2\n");
      }
      else 
      {
        solve_case();
      }
  }  
}