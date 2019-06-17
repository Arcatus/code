#include <iostream>

using namespace std;

int formas(int n)
{
	if (n == 0)
		return 1;
	else {
		int res = 0;
		for (int i = 1; i <= n; ++i)
		{
			res += formas( n - i );
		}
		return res;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	cout << formas(n) << '\n';

	return 0;
}