#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n;
	int arr[n];
	for (int i=0;i<n;++i)
	{	
		cin >> arr[i];
	}
	cin >> k;
	for (int i=0;i<n;++i)
	{	
		if (abs(arr[i]-k) <= 3)
			cout << arr[i] << ' ';
	}
	cout << '\n';

	return 0;
}