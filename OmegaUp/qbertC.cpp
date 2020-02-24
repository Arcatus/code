#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int global_status, costo_global = 101, n;

int numero_salto = 0;

int valores[15+1];

bool validador[ 45+1 ][ 15+1 ];

vector< vector<int> > desplazamientos(15+1);

vector< vector<int> > hexagono = {
	{ -1 },
	{ 2, 3 },
	{ 1, 4, 5 },
	{ 1, 5, 6 },
	{ 2, 7, 8 },
	{ 2, 3, 8, 9 },
	{ 3, 9, 10 },
	{ 4, 11, 12 },
	{ 4, 5, 12, 13 },
	{ 5, 6, 13, 14 },
	{ 6, 14, 15 },
	{ 7 },
	{ 7, 8 },
	{ 8, 9 },
	{ 9, 10 },
	{ 10 }
};

int pasos = 0;

void salta( int nodo_actual )
{
	if ( global_status == 0 ) {
		//cerr << "llegue a una solucion " << numero_salto << "\n";
		costo_global = min(numero_salto, costo_global);
		return;
	}
	
	for(int i=0; i < desplazamientos[ nodo_actual ].size(); ++i) {
		
		if ( validador[ global_status ][ nodo_actual ] ) continue;

		numero_salto += 1;

		int aristas = ???

		if ( numero_salto + global_status + aristas < costo_global ) {

			validador[ global_status ][ nodo_actual ] = true;

			bool backtrack = false;
			if ( valores[ desplazamientos[ nodo_actual ][i] ] > 0 ) {
			
				global_status-=1;
				valores[ desplazamientos[ nodo_actual ][i] ]-=1;
				backtrack=true;

			}

 			salta( desplazamientos[ nodo_actual ][i] );

			if ( backtrack ) {

				global_status+=1;
				valores[ desplazamientos[ nodo_actual ][i] ]+=1;
			}

			validador[ global_status ][ nodo_actual ] = false;
		}

		numero_salto -= 1;
	}
}

int main()
{
	cin >> n;

	for(int i=1; i <= n*(n+1)/2; ++i) {
		for(int j=0; j<hexagono[i].size(); ++j) {
			if ( hexagono[i][j] > n*(n+1)/2 ) {
				continue;
			}
			desplazamientos[i].push_back( hexagono[i][j] );
		}
	}

	int i, j, k;

	global_status = 0;

	for( i = 1, k = 1; i <= n; ++i) {
		for(j = 1; j <= i; ++j) {
			cin >> valores[ k++ ];
			global_status += valores[ k - 1 ];
		}
	}

	if ( global_status == 0 ) {
		cout << "0\n";
	} else {
		for(i=0; i < desplazamientos[1].size(); ++i) {

			if ( validador[ global_status ][ 1 ] ) continue;

			numero_salto += 1;

			bool backtrack=false;

			if ( valores[ desplazamientos[1][i] ] > 0 ) {
				valores[ desplazamientos[1][i] ]-=1;
				global_status-=1;
				backtrack=true;
			}
			salta( desplazamientos[1][i] );
			if ( backtrack ) {
				valores[ desplazamientos[1][i] ]+=1;
				global_status+=1;
			}

			numero_salto -= 1;

		}
		cout << costo_global << '\n';
	}
}