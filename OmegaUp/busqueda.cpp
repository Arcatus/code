#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int arr[n];
	for(int i=0;i<n;++i)
	{		
		cin >> arr[i];
	}

	sort(arr,arr+n);
	int k;
	cin >> k;

	auto t = lower_bound(arr, arr+n, k ) - arr;

	cout << t << '\n';

	return 0;
}