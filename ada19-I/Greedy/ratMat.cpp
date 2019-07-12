#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <climits>

using namespace std;

struct madri{
	int posicion;
	int capacidad = 0;
};

struct raton
{
	int posicion;
	int worst = 0;
	int* distancias;
};

int main()
{
	int n;
	cin >> n;
	raton ratones[n];

	int max_rat = -1;

	for (int i=0; i<n; ++i) {
		cin >> ratones[i].posicion;
		if ( ratones[i].posicion > max_rat ) {
			max_rat = ratones[i].posicion;
		}
	}

	int m;
	cin >> m;
	madri mad[m];

	int min_mad = INT_MAX;
	int max_cap = 0;

	for (int i=0; i<m; ++i) {
		cin >> mad[i].posicion >> mad[i].capacidad;
		if ( mad[i].posicion < min_mad ) {
			min_mad = mad[i].posicion;
		}
		max_cap += mad[i].capacidad;
	}

	if ( max_cap < n) {
		cout << -1 << '\n';
		return 0;
	}

	for (int i=0; i<n; ++i) {
		ratones[i].distancias = new int[m];
		int *handler = ratones[i].distancias;

		for (int j=0; j<m; ++j) {
			handler[j] = abs( ratones[i].posicion - mad[j].posicion );
		}
	}

	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			ratones[i].worst += ratones[i].distancias[j];
		}
	}

	sort( ratones, ratones + n, [](const raton& a, const raton& b){
		return a.worst > b.worst;
	} );
	
	for (int i=0; i<n; ++i) {
		cout << ratones[i].posicion << ' ';
		for (int j=0;j<m;++j)
		{
			cout << ratones[i].distancias[j] << ' ';
		}
		cout << ratones[i].worst << '\n';
	}
	
	auto oraculo = [&](const int& time)
	{
		int indice, minimo;
		vector<int> capacidades;
		for (int i=0;i<m;++i) {
			capacidades.push_back( mad[i].capacidad );
		}
		for (int i=0; i<n; ++i ) {
			indice = -1;
			minimo = INT_MAX;
			vector<int> posibles;

			for (int j=0; j<m; ++j) {
				if ( capacidades[j] > 0 && ratones[i].distancias[j] <= time ) {
					int dist = time - ratones[i].distancias[j];
					if ( dist < minimo) {
						minimo = dist;
						indice = j;
					}
				}
			}
			if ( indice == -1)  {
				cerr << "IMPOSIBLE en tiempo " << time << '\n';
				/*
				for ( auto v: capacidades)
				{
					cout << v << " ";
				}
				cout << '\n';*/
				return false;
			}
			cout << "raton " << ratones[i].posicion << " a " << mad[indice].posicion << '\n';
			capacidades[indice] -= 1;
		}
		cerr << "POSIBLE en tiempo " << time << '\n';
		return true;
	};	
	oraculo(24);
}