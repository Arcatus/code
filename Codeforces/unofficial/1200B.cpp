#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int t;

	cin >> t;

	int n, m, k;

	for (int i=0; i<t; ++i) {

		cin >> n >> m >> k;

		bool ans = true;

		int arr[n];

		for(int k=0; k<n; ++k) cin >> arr[k];

		for (int j=0; j<n-1; ++j) {

			int k_min = max( 0, arr[j+1] - k );

			int requerido = arr[j] - k_min;

			if ( requerido >= 0 ) {
				m += requerido;
			} else {
				if ( arr[j] + m >= k_min ) {
					m += requerido;
				} else {
					cout << "NO\n";
					ans = false;
					break;
				}
			}
		}
		if ( ans ) {
			cout << "YES\n";
		}
	}
}