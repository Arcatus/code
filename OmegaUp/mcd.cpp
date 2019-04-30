#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll gcd(ll x, ll y)
{
	while(y)
	{
		x%=y;
		swap(x,y);
	}
	return x;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll a, b;
	cin >> a >> b;
	cout << gcd(a,b) <<'\n';
	return 0;
}