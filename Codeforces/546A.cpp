#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long k, n, w;

	cin >> k >> n >> w;

	long long ans = 0;

	for(int i=1; i<=w; ++i) {
		ans += k*i;
	}
	if ( ans <= n ) {
		cout << 0 << '\n';
	} else {
		cout << ans - n << '\n';
	}
}