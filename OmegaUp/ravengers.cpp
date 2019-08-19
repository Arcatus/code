#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;

	cin >> n >> m;

	int tablero[n][m];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) { 
			cin >> tablero[i][j];
		}
	}

	
	
}