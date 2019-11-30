#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct posicion_anotada {
	int x;
	int y;
	posicion_anotada* ant;
	int recogido;
};

int main()
{
	int n;
	cin >> n;

	char tablero[n][n];
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			cin >> tablero[i][j];
		}
	}

	int tesoros[n][n];
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			tesoros[i][j] = 0;
		}
	}

	int dx[] = {  0,  1, 0 };
	int dy[] = { -1,  0, 1 };

	int max_tesoros = 0;


	if ( n == 1 ) {
		cout << ( tablero[0][0] == '*' )?1:0 << '\n';
		return 0;
	}

	vector< posicion_anotada > actual;

	posicion_anotada a{ 0, 0, 
		new posicion_anotada{-1,-1}, (tablero[0][0]=='*')?1:0 };
	actual.push_back( a );
	
	posicion_anotada b{ 0, n-1, 
		new posicion_anotada{-1,-1}, (tablero[0][n-1]=='*')?1:0 };
	actual.push_back( b );

	tesoros[0][0]   = (tablero[0][0] == '*');
	tesoros[0][n-1] = (tablero[0][n-1] == '*');

	for (int p=0; !actual.empty(); p++) {

		vector< posicion_anotada > siguiente;

		for ( posicion_anotada procesar : actual ) {
			for ( int i=0; i<3; ++i ) {
				int destinoX = procesar.x + dx[i];
				int destinoY = procesar.y + dy[i];

				if ( 0 <= destinoX && destinoX < n && 0 <= destinoY && destinoY < n && 
					 tablero[destinoX][destinoY] != '#' && 
					 ( procesar.ant->x != destinoX || procesar.ant->y != destinoY ) ) {
					
					int oro = procesar.recogido + (tablero[destinoX][destinoY]=='*');

					if ( oro > tesoros[destinoX][destinoY] ) {
						tesoros[destinoX][destinoY] = oro;
						posicion_anotada nuevo{ destinoX, destinoY, 
								new posicion_anotada{ procesar.x, procesar.y, nullptr, 0 }, oro };
						siguiente.push_back(nuevo);
						
						max_tesoros = max( max_tesoros, oro );

					} else if ( oro == tesoros[destinoX][destinoY] ) {
						posicion_anotada nuevo{ destinoX, destinoY, 
								new posicion_anotada{ procesar.x, procesar.y, nullptr, 0 }, oro };
						siguiente.push_back(nuevo);
						max_tesoros = max( max_tesoros, oro );
					}
				}
			}
		}
		actual.swap(siguiente);
	}
	/*
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			cout << tesoros[i][j] << ' ';
		}
		cout << '\n';
	}
	*/
	cout << max_tesoros << '\n';
}