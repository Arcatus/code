#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct nodo
{
	int nodo_destino;
	int num_pasos;
	int avance_local;
};

bool operator<(const nodo& a, const nodo& b)
{	
	if ( a.avance_local == b.avance_local ) {
		return a.num_pasos > b.num_pasos;
	}
	return a.avance_local > b.avance_local;
}

const int MAX_SALTOS = 45+1;

int global_status = 0, costo_optimo = 10000007;

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

int main()
{
	int n;
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

	for( i = 1, k = 1; i <= n; ++i) {
		for(j = 1; j <= i; ++j) {
			cin >> valores[ k++ ];
			pisos[i] += valores[k - 1];
		}
	}

	priority_queue< nodo > encolador;

	if ( global_status == 0 ) {
		cout << "0\n";
	} else {

		for(i=0; i < desplazamientos[1].size(); ++i) {
			encolador.push( nodo{ 
				desplazamientos[1][i], 1, 
					pisos[ piso_referencia[ desplazamientos[1][i] ] ] - valores[ desplazamientos[1][i]] });
		}


		while (  && !encolador.empty()  )
		{
		}
		cout << costo_optimo << '\n';
	}
}