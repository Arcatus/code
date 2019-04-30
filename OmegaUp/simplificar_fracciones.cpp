#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll gcd(ll x, ll y)
{
	while(y) {
		x%=y;
		swap(x,y);
	}
	return x;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	ll a, b, _gcd;

	for (int i=0;i<n;++i) {
		cin >> a >>b;
		_gcd = gcd(a,b);
		cout << a/_gcd <<' '<< b/_gcd << '\n';
	}
	return 0;
}