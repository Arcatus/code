#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int k;

int formas(int n)
{
	if (n == 0)
	{
		return 1;
	}
	else
	{
		int res = 0;

		for (int i=1; i<=n;++i)
		{
			if (i > 9) continue;
			res += formas(n-i);
		}
		return res;
	}
}

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	//k = stoi(argv[1]);

	cin >> k;

	int ans = formas(k);

	cout << ans << '\n';

	return 0;
}