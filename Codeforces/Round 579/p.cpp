#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int q, n;

	cin >> q;

	while( q-- ) {
		cin >> n;

		int arr[n];

		for(int i=0; i<n; ++i) {
			cin >> arr[i];
		}

		if ( n == 1 ) {
			cout << "YES\n";
			continue;
		}

		bool clockwise = true;
		bool counterClockwise = true;

		for(int i=0; i<n-1; ++i) {
			if (arr[i] == 1 || arr[i+1] == 1)
				continue;
			if ( arr[i]+1 != arr[i+1]) {
				clockwise = false;
				break;
			}
		}
		
		if (arr[0] != 1 && arr[n-1] != 1) {
			if ( arr[0] != arr[n-1]+1 ) {
				clockwise = false;
			}
		}
		

		for(int i=0; i<n-1; ++i) {
			if (arr[i] == 1 || arr[i+1] == 1)
				continue;
			if ( arr[i] != arr[i+1]+1) {
				counterClockwise = false;
				break;
			}
		}	
		
		if (arr[0] != 1 && arr[n-1] != 1) {
			if ( arr[0]+1 != arr[n-1] ) {
				counterClockwise = false;
			}
		}

		if ( clockwise || counterClockwise ) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}