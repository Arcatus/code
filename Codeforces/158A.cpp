#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;

	cin >> n >> k;

	int arr[n+1];
	
	for(int i=1; i<=n; ++i) {
		cin >> arr[i];
	}

	int score = arr[k];
	int ans = 0;
	for(int i=1; i<=n; ++i) {
		if ( arr[i] >= score && arr[i] > 0 ) {
			ans += 1;
		}
	}

	cout << ans << '\n';
}