#include <iostream>

using namespace std;

int n;

int solve(int k)
{
	if( k == n ) {
		return 1;
	} else if( k > n ) {
		return 0;
	}
	return solve(k+1) + solve(k+2);
}

int main()
{
	cin >> n;

	int ans = solve(1);

	cout << ans << '\n';
}