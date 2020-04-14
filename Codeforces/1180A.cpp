#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;
	cin >> n;

	ll ans = (n*n) + (n-1)*(n-1);

	cout << ans << '\n';
}