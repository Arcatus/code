#include <iostream>
#include <algorithm>
using namespace std;

int arr[10000+1][10000+1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	char c;
	int j, i1, i2;
	for(int i=0; i<q; ++i) {
		cin >> c;
		if ( c == 'R' ) {
			cin >> j >> i1 >> i2;
			while( i1 < i2 ) {
				int x = (i2-i1)*n;
				arr[i1][j] += x;
				arr[i2][j] += -x;
				i1++; i2--;
			}
		} else {
			cin >> i1 >> i2;
			cout << i1*n + i2 + 1 + arr[i1][i2] << '\n';
		}
	}
	return 0;
}