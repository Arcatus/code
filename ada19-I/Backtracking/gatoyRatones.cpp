#include <iostream>
#include <climits>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n, m;

int costo_global = INT_MAX, costo_local = -1, distancia;

struct raton
{
	int posicion;
	int volumen;
};

raton ratones[20+1];

struct madriguera
{
	int posicion;
	int capacidad;
};

madriguera madrigueras[20+1];

void huida(int k)
{
	if (k == n) {
		costo_global = min(costo_global,costo_local);
		return;
	}
	for (int j=0; j < m; ++j) {
		if ( ratones[k].volumen <= madrigueras[j].capacidad )
		{
			distancia = abs(ratones[k].posicion - madrigueras[j].posicion);

			int save = costo_local;

			costo_local = max(distancia,costo_local);

			if ( costo_local < costo_global ) {
				madrigueras[j].capacidad -= ratones[k].volumen;
				huida(k+1);
				madrigueras[j].capacidad += ratones[k].volumen;
			}
			costo_local = save;
		}
	}
}

int main()
{

	cin >> n;

	for (int i=0;i<n;++i) {
		cin >> ratones[i].posicion >> ratones[i].volumen;
	}

	cin >> m;

	for (int i=0;i<m;++i) {
		cin >> madrigueras[i].posicion >> madrigueras[i].capacidad;
	}

	sort(ratones, ratones+n,
		[&](raton a, raton b){ return a.volumen > b.volumen; });

	sort(madrigueras, madrigueras+m,
		[&](madriguera a, madriguera b){ return a.capacidad > b.capacidad; });

	huida(0);

	if (costo_global == INT_MAX)
		cout << "-1" << '\n';
	else
		cout << costo_global << '\n';

	return 0;
}