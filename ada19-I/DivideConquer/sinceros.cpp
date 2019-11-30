#include <iostream>

using namespace std;

long long formas(int n, int k)
{
  if (n == 0 || k == 0) {
      return 1;
  }
  else if (n == 1) {
      return 2;
  }
  else
  {
      return formas(n-1,k) + formas(n-2,k-1);
  }
}

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);
	int n, k;
    cin >> n >> k;
    cout << formas(n,k) << '\n';
    return 0;
}