
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int capacidad[1000000+1];
bool madriguera[1000000+1];

struct raton
{
	int optimo;
	int posicion;
	bool direction;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	raton ratones[n];

	for (int i=0;i<n;++i) {
		cin >> ratones[i].posicion;
	}

	int m;
	cin >> m;

	int max_mad = 0, p, c;

	int tope = -1;

	for (int i=0;i<m;++i) {
		cin >> p >> c;
		madriguera[p] = true;
		max_mad += c;
		//capacidad[p] = c;
		capacidad[p] = INT_MAX;
		tope = max( tope, p );
	}
	
	int optimo_distancia = 0;

	if ( n > max_mad ) {
		cout << -1 << '\n';
	}
	else
	{
		for (int i=0; i<n ;++i) {

			int optimoL = INT_MAX;
			int optimoR = INT_MAX;

			for (int j=ratones[i].posicion; j <= tope; ++j) {
				if ( madriguera[j] ) {
					optimoR = j - ratones[i].posicion;
					break;
				}
			}
			for (int j=ratones[i].posicion; j >= 0; --j) {
				if ( madriguera[j] ) {
					optimoL = ratones[i].posicion - j;
					break;
				}
			}
			if ( optimoL < optimoR) {
				ratones[i].optimo = optimoL;
				ratones[i].direction = true;
			} else {
				ratones[i].optimo = optimoR;
				ratones[i].direction = false;
			}
		}

		sort(ratones, ratones + n, [](const raton& a, const raton& b) {
			return a.optimo > b.optimo;
		} );

		int ans = -1;

		for (int i=0; i<n; ++i)
		{
			if ( ratones[i].direction ) { 
				int offset = ratones[i].posicion - ratones[i].optimo;
				if ( madriguera[ offset ] ) {
					cout << "rL " << ratones[i].posicion << " -> " << offset << '\n';
					ans = max( ans, ratones[i].optimo );
					capacidad[ offset ]-=1;
					if ( capacidad[ offset ] == 0 ) {
						madriguera[ offset ] = false;
					}
					continue;
				}				
			} else {
				int offset = ratones[i].posicion + ratones[i].optimo;
				if ( madriguera[ offset ] ) {
					cout << "rR " << ratones[i].posicion << " -> " << offset << '\n';
					ans = max( ans, ratones[i].optimo );
					capacidad[ offset ]-=1;
					if ( capacidad[ offset ] == 0 ) {
						madriguera[ offset ] = false;
					}
					continue;
				}
			}

			int posibleR = INT_MAX, posibleL= INT_MAX;
			int offset = ratones[i].posicion;

			for (int i=offset; i <= tope; ++i) {
				if ( madriguera[i] ) {
					posibleR = i - offset;
					break;
				}
			}
			for (int i=offset; i >= 0; --i) {
				if ( madriguera[i] ) {
					posibleL = offset - i;
					break;
				}
			}
			if ( posibleL < posibleR ) {
				cout << "r2L " << ratones[i].posicion << " -> " << offset - posibleL << '\n';
				ans = max( ans, posibleL );
				capacidad[ratones[i].posicion - posibleL]-=1;
				if (capacidad[ratones[i].posicion - posibleL] == 0 ) {
					madriguera[ratones[i].posicion - posibleL] = false;
				}
			} else {
				cout << "r2R " << ratones[i].posicion << " -> " << posibleR + offset << '\n';
				ans = max( ans, posibleR );
				capacidad[offset + posibleR]-=1;
				if (capacidad[offset + posibleR] == 0 ) {
					madriguera[offset + posibleR] = false;
				}
			}
		}
		for ( int i = 0; i <= tope; ++i ) {
			if ( madriguera[i] == true ) {
			 	cout << i << " usados: " << INT_MAX - capacidad[i] << '\n';
			}
		}
		cout << "Optimal " << ans << '\n';
	}
}