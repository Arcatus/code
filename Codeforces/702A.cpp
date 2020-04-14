#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	
	int arr[n];

	cin >> arr[0];
	int ans = 1;
	int tmp = 1;
	for(int i=1; i<n; ++i) {
		cin >> arr[i];
		if ( arr[i] > arr[i-1] ) {
			tmp +=1;
		} else if ( arr[i] <= arr[i-1] ) {
			ans = max(ans, tmp);
			tmp = 1;
		}
	}
	ans = max(ans, tmp);
	cout << ans << '\n';
}