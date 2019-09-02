#pragma GCC optimize ("Ofast", "unroll-loops")

#include <iostream>

using namespace std;

bool arr[100+1][100+1];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;

	cin >> n >> m;

	int x, y;
	for(int i=0; i<m; ++i) {
		cin >> x >> y;
		arr[x][y] = true;
		arr[y][x] = true;
	}
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
}