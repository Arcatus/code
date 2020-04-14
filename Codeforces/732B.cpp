#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;

	cin >> n >> k;

	int arr[n+2];
	arr[0] = k;
	arr[n+1] = k;

	for(int i=1; i<=n; ++i) {
		cin >> arr[i];
	}
	int ans = 0;
	for(int i=1; i<=n; ++i) {
		if ( arr[i] + arr[i-1] < k ) {
			ans += k - arr[i-1] - arr[i];
			arr[i] = k - arr[i-1]; // greedy
		}
	}
	cout << ans << '\n';
	for(int i=1; i<=n; ++i) {
		cout << arr[i] << ' ';
	}
}