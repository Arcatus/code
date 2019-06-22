#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	int arr[n];
	cin >> arr[0];
	for (int i=1;i<n;++i) {
		cin >> arr[i];
		arr[i] += arr[i-1];
	}
	int m;
	cin >> m;
	int v, k;
	for (int i=0;i<m;++i)
	{
		cin >> v >> k;
		if ( k != 0 ) {
			v += arr[k-1];
		}
		auto res = lower_bound(arr, arr+n, v) - arr;

		cout << res << '\n';
	}
	return 0;
}