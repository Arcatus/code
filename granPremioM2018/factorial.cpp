#include <iostream>

using namespace std;

typedef long long ll;

ll factorial(ll n)
{
	if (n==0)
		return 1;
	return n*factorial(n-1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i=0;i<=12;++i)
	{
		cout << factorial(i) << '\n';
	}
	return 0;
}