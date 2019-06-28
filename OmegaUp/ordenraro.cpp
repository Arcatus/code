#include <iostream>
#include <algorithm>

using namespace std;

const int divisores[] =
{
	 0, 1,  2, 2,  3, 2,  4, 2,  4, 3,
	 4, 2,  6, 2,  4, 4,  5, 2,  6, 2,
	 6, 4,  4, 2,  8, 3,  4, 4,  6, 2,
	 8, 2,  6, 4,  4, 4,  9, 2,  4, 4,
	 8, 2,  8, 2,  6, 6,  4, 2, 10, 3,
	 6, 4,  6, 2,  8, 4,  8, 4,  4, 2,
	12, 2,  4, 6,  7, 4,  8, 2,  6, 4,
	 8, 2, 12, 2,  4, 6,  6, 4,  8, 2,
	10, 5,  4, 2, 12, 4,  4, 4,  8, 2,
	12, 4,  6, 4,  4, 4, 12, 2,  6, 6,
	9
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	int arr[n];

	for (int i=0;i<n;++i)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n, [](const int& a, const int& b) {
		return (divisores[a] == divisores[b])?(a > b):(divisores[a] < divisores[b]);
	} );

	for (auto i: arr) cout << i << ' ';
}