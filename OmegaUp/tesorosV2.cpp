#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;

	char tablero[n][n];
	for(int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			cin >> tablero[i][j];
		}
	}

	vector<int> tracking;

	int oro = 0;

	for (int j=0; j<n; ++j) {

		tracking.push_back(j);

		if ( tablero[0][j] == '*') {
			oro += 1;
		}
	}
	
	int tesoro[n][n];
	
	for(int k=0; k<n; ++k) {
		tesoro[0][k] = oro;
	}
	
	int i, j;	

	for(i=1; !tracking.empty(); ; ++i) {

		vector<int> siguiente;

		for (int j: tracking ) {

			if ( tablero[i][j] == '.' || tablero[i][j] == '*' ) {03ee45	5	q	q
				
			}
		}
		actual.swap(siguiente);
	}
}