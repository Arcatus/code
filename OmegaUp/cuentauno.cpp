#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll a, b, n, k, res, last;

	cin >> n;

	for (ll j=0; j<n; ++j) 
	{
		cin >> a >> b;

		res = 0;

		for (ll i=a;i<=b;++i)
		{
			k = i;
			while(k)
			{
				last = k % 10LL;

				if ( last == 1LL )
				{
					res += 1LL;
				}
				k /= 10LL;
			}
		}
		cout << res << '\n';
	}
	return 0;
}