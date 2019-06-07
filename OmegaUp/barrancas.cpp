#include <iostream>
#include <climits>

using namespace std;

unsigned int espec[50000 + 1];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, k, max = INT_MIN;

	cin >> n >> k;

	for (int i = 0; i < n; ++i) cin >> espec[i];

	if ( n - k > 0 ) 
	{
		for (int i = 0; i <= n - k; i++)
		{
			int max_n = espec[i + k - 1] - espec[i];
			if ( max_n > max) max = max_n;
		}
	} else {
		max = espec[k - 1] - espec[0];
	}
	cout << max << '\n';

	return 0;
}