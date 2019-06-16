#include <iostream>

using namespace std;

long long potencia(int a, int b)
{
    if ( b == 0) return 0;
    else if ( b == 1) return a;
    else
    {
        long long res = potencia(a,b/2);
        
        res = res*res;
        
        if ( b & 1 ) res = res*a;
        
        return res;
    }
}


long long best(int n)
{
  if (n <= 1) return 0;
  else 
  {
  	return (best(n-1)<<1) + potencia(2,n-1);
  }
}

int main()
{
	ios::sync_with_stdio(false);
  cin.tie(0);
	int n;
  cin >> n;
  
  cout << best(n) << '\n';
  return 0;
}