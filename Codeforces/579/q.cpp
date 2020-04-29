#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int q;

	cin >> q;

	while ( q-- ) {
		int n;
		cin >> n;

		int arr[4*n];

		for(int i=0; i<4*n; ++i) {
			cin >> arr[i];
		}

		sort(arr, arr+(4*n) );

		vector<int> posibles;

		int shouldClose = false;

		for(int i=0; i<4*n; i+=2) {
			if ( arr[i] != arr[i+1]) {
				cout << "NO\n";
				shouldClose = true;
				break;
			}
			posibles.push_back( arr[i] );
		}

		if ( shouldClose ) continue;

		int areaUnica = posibles[0]*posibles[ posibles.size()-1];

		for(int i=0; i < posibles.size()/2 ; i+=2) {
			int a = posibles[i]*posibles[posibles.size()-i-1];
			int b = posibles[i+1]*posibles[posibles.size()-i-2];

			if ( a != areaUnica || b != areaUnica ) {
				cout << "NO\n";
				shouldClose = true;
				break;
			}
		}

		if ( shouldClose ) continue;

		cout << "YES\n";
	}
}