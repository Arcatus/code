#include <iostream>

using namespace std;

int best(int n)
{
	if (n <= 1) return 0;
  else 
  {
  	return (best(n>>1)<<1) + (n >> 1);
  }
}

int worst(int n)
{
	if (n <= 1) return 0;
  else 
  {
  	return (worst(n>>1)<<1) + (n - 1);
  }
}


int main()
{
	ios::sync_with_stdio(false);
  cin.tie(0);
	int n;
  cin >> n;
  
  cout << best(n) << " " << worst(n) << '\n';
  return 0;
}