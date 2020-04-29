#include <iostream>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd( b, a % b );
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;

	ll x;
	ll tmp = 0;

	while( n-- ) {
		cin >> x;
		tmp = gcd(tmp,x);
	}

	ll ans = 0;

	for (ll i=1; i*i<=tmp; ++i) {
		if ( tmp % i == 0 ) {
			if ( tmp/i == i ) {
				ans += 1;
			} else {
				ans += 2;
			}
		}
	}
	cout << ans << '\n';
}