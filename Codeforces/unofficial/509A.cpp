#include <iostream>

using namespace std;

int main()
{
	int n;

	cin >> n;

	int table[n+1][n+1];

	for(int i=1; i<=n; ++i) {
		table[1][i] = table[i][1] = 1;
	}

	for(int i=2; i<=n; ++i ) {
		for(int j=2; j<=n; ++j ) {
			table[i][j] = table[i-1][j] + table[i][j-1];
		}
	}
	cout << table[n][n] << '\n';
}