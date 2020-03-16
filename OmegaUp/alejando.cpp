#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <utility>
#include <vector>
#include <cstring>
#include <limits>
#include <unordered_map>

using namespace std;

int matady[50+1][50+1];

struct registro {
	int vertice;
	int distancia;
	int padre;
};

struct robot {
	int vertice;
	int energia;
};

struct bomba {
	float posicion;
	bool sobreArista = false;
	pair<int,int> arista;
	int vertice;
};

bool operator<(const registro& a, const registro& b)
{
	return a.distancia > b.distancia;
}

bool operator<(const bomba& a, const bomba& b)
{
	return a.posicion < b.posicion;
}

int main()
{
	int n;

	cin >> n;

	int shortestPaths[n][n];

	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			cin >> matady[i][j], shortestPaths[i][j] = -1;
		}
	}
	
	int parents[n][n];
	
	for(int i=0; i<n; ++i) {

		priority_queue< registro > cola;

		cola.push( registro{ i, 0, -1 } );

		while( !cola.empty() )
		{
			registro temp = cola.top();
			cola.pop();

			if ( shortestPaths[i][temp.vertice] == -1 ) {

				parents[i][temp.vertice] = temp.padre;

				shortestPaths[i][temp.vertice] = temp.distancia;

				int *desp =  matady[ temp.vertice ];

				for(int j=0; j<n; ++j ) {
					if ( desp[j] != 0 ) {
						cola.push( registro{ j, temp.distancia + desp[j], temp.vertice } );
					}
				}
			}
		}
	}

	map< pair<int,int>, vector<int> > paths;

	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			if ( i==j ) continue;
			vector<int> route;
			int k = j;
			route.push_back(k);
			 while( parents[i][k] != -1 ) {
				route.push_back( parents[i][k] );
				k = parents[i][k];
			}
			for(int r=route.size()-1; r >= 0; --r) {
				paths[{i,j}].push_back( route[r] );
			}
		}
	}

	map< pair<int,int>, float > aristas;

	int *distancias = shortestPaths[0];

	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			if( i==j )continue;

			auto [v_ini,v_fin] = make_pair(min(i,j), max(i,j));

			if ( aristas.count( { v_ini, v_fin } ) == 0  ) {
				if ( distancias[v_ini] == distancias[v_fin] ) {
					aristas[ { v_ini, v_fin } ] 
						= (float) distancias[v_ini] + matady[v_ini][v_fin]/2.0f;
				} else if ( distancias[v_ini] + matady[v_ini][v_fin] == distancias[v_fin] ) {
					aristas[ { v_ini, v_fin } ] 
						= (float) distancias[v_fin];
				} else if ( distancias[v_ini] + matady[v_ini][v_fin] > distancias[v_fin] ) {
					aristas[ { v_ini, v_fin } ] 
						= (float)((distancias[v_ini] + matady[v_ini][v_fin])+distancias[v_fin])/2.0f;
				}
			}
		}
	}

	int R;

	cin >> R;

	robot robots[R];

	int toReach = 0;

	for(int i=0; i<R; ++i) {
		cin >> robots[i].vertice >> robots[i].energia;
		if ( shortestPaths[0][robots[i].vertice] > toReach ) {
			toReach = robots[i].vertice;
		}
	}
	
	bomba mibomba{ 0.0f, false, {-1,-1}, 0};

	for(int i=0; i<R; ++i) {

		if ( mibomba.sobreArista ) {

		} else {
			if ( shortestPaths[ robots[i].vertice ][ mibomba.vertice ] < robots[i].energia ) {
				robots[i].energia -= shortestPaths[ robots[i].vertice ][ mibomba.vertice ];
				
				if( i < R-1 ) {

					int siguienteRobot = robots[i+1].vertice;

					int inicioBomba = mibomba.vertice;

					while( robots[i].energia > 0 && inicioBomba != siguienteRobot && paths[{inicioBomba,siguienteRobot}].size() > 0 ) {
						for(int nxt=1; nxt<paths[{inicioBomba,siguienteRobot}].size(); ++nxt ) {
							int costo_local = shortestPaths[ inicioBomba ][ paths[{inicioBomba,siguienteRobot}][nxt] ];
							if ( robots[i].energia >= costo_local ) {
								mibomba.posicion += (float)robots[i].energia;
								mibomba.vertice = paths[{inicioBomba,siguienteRobot}][nxt];
							} else { 
								mibomba.posicion += robots[i].energia;
								robots[i].energia = 0;
								mibomba.sobreArista = true;
							}
						}
					}
				} else {
					float cota_superior = 0.0f;

					for(int k=0; k<n; +k) {
					 	if ( cota_superior < aristas[{ mibomba.vertice, k }] ) {
					 		cota_superior = aristas[{ mibomba.vertice, k }];
					 	}
					}
				}
			}
		}
	}
	cout << mibomba.posicion << '\n';
}