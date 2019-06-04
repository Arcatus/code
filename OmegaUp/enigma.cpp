#include <iostream>

using namespace std;

int arr[100000+1];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, t;
	cin >> n;

	for (int i=1; i <= n; ++i)
	{
		cin >> t;
		arr[i] += arr[i-1] + t;
	}
	cin >> t;

	int a, b;
	for (int j=0; j < t; ++j )
	{
		cin >> a >> b;

		cout << arr[b] - arr[a-1] << '\n';
	}

	return 0;
}