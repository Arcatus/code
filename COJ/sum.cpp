#include <iostream>
using namespace std;

typedef long long ll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;
	cin >> n;

	if (n == 0) {
		printf("1\n");
		return 0;
	}

	int res = 0;

	if (n < 0) {
		for ( int i=1; i >= n; i--)
			res += i;
	}
	else {
		for ( int i=1; i <= n; i++) 
			res += i;
	}
	cout << res << '\n';

	return 0;
}