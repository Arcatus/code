#include <iostream>
using namespace std;

typedef long long ll;

ll gcd(ll x, ll y) {
	return y == 0 ? x : gcd(y, x % y);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll x, y;

	cin >> x >> y;

	ll ans = gcd(x,y);

	cout << ans << '\n';
}