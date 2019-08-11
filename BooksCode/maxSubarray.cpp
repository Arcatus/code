#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int best = 0, sum = 0;

	int array[n];

	for (int i=0;i<n;++i){
		cin >> array[i];
	}

	for (int k = 0; k < n; k++)
	{
		sum = max( array[k], sum + array[k]);
		best = max(best,sum);
	}

	 cout << best << '\n';
}