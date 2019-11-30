#include <iostream>

using namespace std;

long long fichas(int n)
{
	if (n <= 1) {
		return 1;
	} 
	else 
	{
		return fichas(n-1) + fichas(n-2);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	long long res = fichas(n);

	long long ans = res;

	for (int i=0;i<n-1;++i)
	{
		ans*= res;
	}

	cout << ans << '\n';

	return 0;
}