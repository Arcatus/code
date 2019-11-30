#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct arista {
	int vertice;
	long long distancia;
	int costo;
};

bool operator<(const arista& a, const arista& b)
{	
	if ( a.distancia == b.distancia ) {
		return a.costo > b.costo;
	}
	return a.distancia > b.distancia;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int a, b, l, c;

	vector< arista > adjList[n];

	for(int i=0; i<m; ++i) {
		cin >> a >> b >> l >> c;
		adjList[a-1].push_back( arista{ b-1, l, c } );
		adjList[b-1].push_back( arista{ a-1, l, c } );
	}
	
	int costos[n];
	long long distancias[n];

	fill(costos, costos+n, -1);
	fill(distancias, distancias+n, -1);

	std::priority_queue< arista > cola;

	cola.push( arista{ 0, 0, 0} );

	int subsets = n;

	while( subsets > 0 && !cola.empty() ) {
		arista procesar = cola.top();
		cola.pop();

		if ( distancias[procesar.vertice] == -1 ) {
			subsets -= 1;
			distancias[procesar.vertice] = procesar.distancia;
			costos[procesar.vertice] = procesar.costo;
			for(auto vecino: adjList[procesar.vertice] ) {
				cola.push( arista{ vecino.vertice, vecino.distancia + procesar.distancia, vecino.costo } );
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += costos[i];
	}

	cout << ans << '\n';
}