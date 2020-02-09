#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;

	cin >> n;

	int arr[n+1];

	for(int i=1; i<=n; ++i) {
		cin >> arr[i];
	}

	int ans[n+1];

	std::fill(ans, ans+n+1, 0);

	for(int i=1; i<=n; ++i)
	{
		ans[i]++;

		int l = i-1;
		while( l > 0 && arr[i] > arr[l] ) {
			ans[i]++;
			l--;
		}

		int r = i+1;
		while( r <= n && arr[i] > arr[r] ) {
			ans[i]++;
			r++;
		}
	}
	for(int i=1; i<=n; ++i) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}