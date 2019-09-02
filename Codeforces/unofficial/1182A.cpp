#include <iostream>

using namespace std;

int memoization[60+1];

int solve(int n) {
	if ( n == 0 ) {
		return 1;
	}
	if ( memoization[n] == -1 ) {
		memoization[n] = solve(n-2) + solve(n-2);
	}
	return memoization[n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;

	if ( n & 1 || n == 0 ) {
		cout << 0 << '\n';
		return 0;
	}

	fill(memoization, memoization+n+1, -1);

	int ans = solve(n);

	cout << ans << '\n';
}