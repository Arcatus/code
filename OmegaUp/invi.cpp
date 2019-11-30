#include <iostream>
#include <algorithm>
using namespace std;

int arr[10000+1][10000+1];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, q;

	cin >> n >> q;

	for(int i=0;i<n;++i) 
		for(int j=0;j<n;++j) arr[i][j]=i*n+j+1;

	char c;
	int j, i1, i2;

	for(int i=0; i<q; ++i) {
		cin >> c;
		if ( c == 'R' ) {
			cin >> j >> i1 >> i2;
			for(int up=i1, down = i2; up < down; up++, down--) {
				swap( arr[up][j], arr[down][j] );
			}
		} else {
			cin >> i1 >> i2;
			cout << arr[i1][i2] << '\n';
		}
	}
}