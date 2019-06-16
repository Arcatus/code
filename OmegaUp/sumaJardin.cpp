#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int array[n];

	for (int i=0;i<n;++i)
	{	
		cin >> array[i];
	}

	int best = 0;
	for (int a = 0; a < n; a++) {
		for (int b = a; b < n; b++) {
			int sum = 0;
			for (int k = a; k <= b; k++) {
				sum += array[k];
			}
			
		}
	}
	cout << best << "\n";

	return 0;
}