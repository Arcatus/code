#pragma GCC optimize("Ofast","unroll-loops")
#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n;
	int x, y;
	if ( n == 0 ) {
		cin >> m;
		for(int i=0; i<m; ++i) {
			cin >> x  >> y;
			cout << 0 << '\n';
		}
	} else {
		int arr[n+1];
		arr[0] = 0;
		cin >> arr[1];
		for(int i=2; i<=n; ++i) {
			cin >> arr[i];
			arr[i] += arr[i-1];
		}
		cin >> m;
		for(int i=0; i<m; ++i) {
			cin >> x >> y;
			cout << arr[y+1] - arr[x] << '\n';
		}
	}
}