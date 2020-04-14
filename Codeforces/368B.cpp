#include <iostream>
#include <set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;

	cin >> n >> m;

	int arr[n];

	for(int i=0; i<n; ++i) {
		cin >> arr[i];
	}
	int dp[n];
	set<int> memo;
	int contador=0;

	for(int i=n-1; i>=0; i--) {
		if ( memo.count(arr[i]) == 0 ) {
			contador += 1;
			memo.insert( arr[i] );
			dp[i] = contador;
		} else {
			dp[i] = dp[i+1];
		}
	}
	int q;
	while( m-- ) {
		cin >> q;
		cout << dp[q-1] << '\n';
	}
}