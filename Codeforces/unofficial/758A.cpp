#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int arr[n];

	for(int i=0; i<n;++i) {
		cin >> arr[i];
	}

	sort( arr, arr+n );

	int ans = 0;

	for(int i=0; i < n; ++i) {
		if ( arr[n-1] == arr[i] ) break;
		ans += arr[n-1] - arr[i];
	}

	cout << ans << '\n';
}