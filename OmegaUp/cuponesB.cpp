#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits>
#include <set>

using namespace std;

struct vecino {
   int vertice, longitud;
};

struct registro {
   int vertice, distancia;
};

struct arista {
   int origen, destino, costo;
};

bool operator<(const registro& r1, const registro& r2) {
   return r1.distancia > r2.distancia;
}

bool operator<(const arista& a, const arista& b) {
   return a.costo > b.costo;
}

int main( ) 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;

	vector< vecino > adyacencia[n];

   set< arista > aristas;

	for (int i = 0; i < m; ++i) {
      int x, y, c;
      std::cin >> x >> y >> c;
      adyacencia[x].push_back(vecino{y, c});
      adyacencia[y].push_back(vecino{x, c});
      aristas.insert( arista{ min(x,y),max(x,y), c} );
   }

   for(auto i: aristas) {
      cout << i.origen << " " << i.destino << " " << i.costo << '\n';
   }

   int distancias[n];
  	
   fill( distancias, distancias + n, -1);

  	priority_queue<registro> cola;

  	cola.push( registro{ 0, 0} );

  	while ( !cola.empty() ) {
      registro procesar = cola.top();
      cola.pop( );
      
      if (distancias[procesar.vertice] == -1) {
         
         distancias[procesar.vertice] = procesar.distancia;

         for (auto vecino : adyacencia[procesar.vertice]) {
            cola.push( registro{vecino.vertice, vecino.longitud + procesar.distancia} );
         }
      }
    }

    cout << distancias[ n - 1 ] << '\n';
}