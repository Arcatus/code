#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, oro = 0;
	cin >> n;

	char tablero[n][n];
	for(int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			cin >> tablero[i][j];
		}
	}

	for (int j=0; j<n; ++j) {
		if ( tablero[0][j] == '*') {
			oro += 1;
		}
	}
	
	int tesoro[2][n];

	for(int k=0; k<n; ++k) {
		tesoro[0][k] = oro;
	}
	int ans = max( 0, tesoro[0][0] );

	int* anterior  = tesoro[0];
	int* siguiente = tesoro[1];

	bool posibles[2][n];

	for (int i=0; i<n; ++i ) {
		posibles[0][i] = true;
	}
	bool* alcanzable = posibles[0];
	bool* posible    = posibles[1];

	for (int i=1; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			if ( alcanzable[j] && ( tablero[i][j] == '.' || tablero[i][j] == '*' ) ) {
				int contador = 0, ini = j, ant_max = -1;
				int forward = j, backward = j;
				while ( forward < n && tablero[i][forward] != '#' )	 {
					posible[forward] = true;
					if ( anterior[forward] != -1) {
						ant_max = max( ant_max, anterior[forward] );
					}
					if ( tablero[i][forward] == '*' ) {
						contador += 1;
					}
					forward+=1;
				}
				backward-=1;
				while ( backward >= 0 && tablero[i][backward] != '#' )	 {
					posible[backward] = true;
					if ( anterior[backward] != -1) {
						ant_max = max( ant_max, anterior[backward] );
					}
					if ( tablero[i][backward] == '*' ) {
						contador += 1;
					}
					backward-=1;
				}
				contador += ant_max;
				for (int k=backward+1; k<forward; ++k) {
					siguiente[k] = contador;
				}
				ans = max(ans, contador);
				
				if ( tablero[i][backward] == '#' ) {
					siguiente[backward] = -1, posible[backward] = false;
				}
				if ( tablero[i][forward] == '#' ) {
					siguiente[forward] = -1, posible[forward] = false;
				}
				j = forward;
			} else {
				siguiente[j] = -1;
				posible[j] = false;
			}
		}
		swap( anterior, siguiente );
		swap( alcanzable, posible );
	}

	cout << ans << '\n';
}