#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;

	long long best = -100000000000LL;
	long long  sum = -100000000000LL;

	long long actual;
	for (int k = 0; k < n; k++)
	{
		cin >> actual;
		sum = max( actual, sum + actual);
		best = max(best,sum);
	}

	cout << best << '\n';
}