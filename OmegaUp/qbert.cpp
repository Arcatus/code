#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

enum { BAJAR, SUBIR };

const int MAX_SALTOS = 45+1;

int global_status = 0, costo_global = 101, n;

int numero_salto = 0;

int valores[15+1];

int pisos[5+1]; 

int piso_referencia[15+1] = {
	-1, 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5
};

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

void salta( int nodo_actual )
{
	/*
	cerr << " global_status " << global_status << '\n';
	cerr << " numero_salto " << numero_salto << '\n';
	cerr << " costo_global " << costo_global << '\n';
	
 	pasos++;
	if ( pasos > 10 ) {-
		cerr << "costo_global " << costo_global << '\n';
		exit(0);
	}
	*/
	if ( global_status == 0 ) {
		costo_global = min(numero_salto, costo_global);
		return;
	}
	
	for(int i=0; i < desplazamientos[ nodo_actual ].size(); ++i) {
		

		int n_piso = piso_referencia[ nodo_actual ];
		int leftUp = 0, leftDown = 0;

		for(int k=n_piso+1; k<=n; ++k ) { leftDown += pisos[k]; }
		for(int k=n_piso-1; k>=1; --k ) { leftUp   += pisos[k]; }

		int destino = ( desplazamientos[nodo_actual][i] > nodo_actual ) ? BAJAR : SUBIR;
			
		if ( destino == BAJAR && leftDown == 0 ) {
			continue;
		} else if ( destino == SUBIR && leftUp == 0) {
			continue;
		}

		numero_salto += 1;

		if ( numero_salto < MAX_SALTOS && numero_salto < costo_global ) {
			//cerr << "saltando de " << nodo_actual << " -> " << desplazamientos[ nodo_actual ][i] << '\n';
			bool backtrack = false;
			if ( valores[ desplazamientos[ nodo_actual ][i] ] > 0 ) {
				global_status-=1;
				valores[ desplazamientos[ nodo_actual ][i] ]-=1;
				pisos[ piso_referencia[ desplazamientos[ nodo_actual ][i] ] ]--;
				backtrack=true;
			}

 			salta( desplazamientos[ nodo_actual ][i] );

			if ( backtrack ) {
				global_status+=1;
				valores[ desplazamientos[ nodo_actual ][i] ]+=1;
				pisos[ piso_referencia[ desplazamientos[ nodo_actual ][i] ] ]++;
			}
		}
		numero_salto -= 1;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

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
			pisos[i] += valores[k - 1];
		}
	}	

	if ( global_status == 0 ) {
		cout << "0\n";
	} else {
		for(i=0; i < desplazamientos[1].size(); ++i) {
			numero_salto += 1;
			//cerr << "saltando de " << 1 << " -> " << desplazamientos[ 1 ][i] << '\n';
			bool backtrack=false;
			if ( valores[ desplazamientos[1][i] ] > 0 ) {
				valores[ desplazamientos[1][i] ]-=1;
				pisos[ piso_referencia[ desplazamientos[1][i] ] ]--;
				global_status-=1;
				backtrack=true;
			}
			salta( desplazamientos[1][i] );
			if ( backtrack ) {
				valores[ desplazamientos[1][i] ]+=1;
				pisos[ piso_referencia[ desplazamientos[1][i] ] ]++;
				global_status+=1;
			}
			numero_salto -= 1;

		} 
		cout << costo_global << '\n';
	}
}