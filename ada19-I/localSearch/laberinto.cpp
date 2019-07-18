#include <iostream>
#include <cstring>
#include <climits>
#include <vector>
#include <tuple>

using namespace std;

typedef pair<int,int> ii;

int main()
{
	int lobos, n;
	cin >> lobos >> n;

	char tablero[n][n];

	ii inicio, final;

	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			cin >> tablero[i][j];
			if ( tablero[i][j] == 'E' ) {
				inicio.first = i;
				inicio.second = j;
			}
			else if( tablero[i][j] == 'S' ) {
				final.first = i;
				final.second = j;
			}
		}
	}
	int enfrentamiento[n][n];

	for (int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			enfrentamiento[i][j] = 11;
		}
	}

	enfrentamiento[ inicio.first ][ inicio.second ] = 0;

	vector< tuple<int, int, int> > actual;

	actual.push_back( make_tuple(inicio.first, inicio.second, 0) );

	int dx[] = { 1, 0, -1,  0 };
	int dy[] = { 0, 1,  0, -1 };

	for (int i=0; !actual.empty(); ++i) {
		
		vector< tuple<int, int, int> > siguiente;

		for (int k=0; k < actual.size(); ++k) {

			int fila, columna, distance;
			tie(fila, columna, distance) = actual[k];

			if ( fila == final.first && columna == final.second ) {
				cout << i << '\n';
				goto salir;
			}

			for (int f=0; f<4; ++f) {
				if ( 0 <= fila+dy[f] && fila+dy[f] < n && 
					 0 <= columna+dx[f] && columna+dx[f] < n && 
					 tablero[fila+dy[f]][columna+dx[f]] != '#' ) 
				{
					tuple<int, int, int> sig = make_tuple(fila+dy[f], columna+dx[f], 
						distance+(tablero[fila+dy[f]][columna+dx[f]] == '*'));

					if ( get<2>(sig) <= lobos && get<2>(sig) < enfrentamiento[fila+dy[f]][columna+dx[f]] )
					{
						siguiente.push_back( sig );
						enfrentamiento[fila+dy[f]][columna+dx[f]] = get<2>(sig);
					}
				}
			}
		}
		actual.swap(siguiente);
	}
	cout << -1 << '\n';
	salir:;

	for (int i=0; i<n; ++i)
	{
		for (int j=0; j<n; ++j) {
			cout << enfrentamiento[i][j] << '\t';
		}
		cout << '\n';
	}
}