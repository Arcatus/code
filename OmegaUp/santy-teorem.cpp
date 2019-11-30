#include <cstdio>
#include <cmath>

int n;
bool p[2000010];

void compute_prime_table(int k)
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
  int c;
  scanf("%d",&c);
  if (c == 1)
  {
      compute_prime_table(100);
  }
  else if ( c <= 10 )
  {
      compute_prime_table(10000);
  }
  else
  {
      compute_prime_table(2000000);
  }

  for (int i=0;i<c;++i)
  {
      scanf("%d",&n);
      solve_case();
  }  
}