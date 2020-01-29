#include <iostream>
#include <numeric>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	
	cin.tie(0);
	cout.tie(0);

	int n, k, in, sum;

	cin >> n >> k;

	int arr[n];

	for(int i=0; i<n; ++i) {
		cin >> arr[i];
	}
	
	sum = accumulate(arr, arr+k, 0);

	cout << sum << " ";

	int j = k;

	while( j < n ) {
		sum = sum - arr[j-k] + arr[j];
		cout << sum << " ";
		j++;
	}
	cout << '\n';
}