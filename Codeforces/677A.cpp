#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;

	cin >> n >> k;

	int ans=0;
	int x;
	for(int i=0; i<n; ++i) {
		cin >> x;
		if ( x > k ) {
			ans += 2;
		} else {
			ans += 1;
		}
	}
	cout << ans << '\n';
}