#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

struct vecino {
   int vertice, longitud;
};

struct registro {
   int vertice, distancia;
   bool cupon_valido;
};

bool operator<(const registro& r1, const registro& r2) {
   return r1.distancia > r2.distancia;
}

int main( ) 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;

	vector< vecino > adyacencia[n];

	for (int i = 0; i < m; ++i) {
      int x, y, c;
      std::cin >> x >> y >> c;
      adyacencia[x].push_back(vecino{y, c});
      adyacencia[y].push_back(vecino{x, c});
   	}
   	int distancias[n];

   	fill( distancias, distancias + n, -1);

   	priority_queue<registro> cola;

   	cola.push( registro{ 0, 0, true } );

   	while ( !cola.empty() ) {

      registro procesar = cola.top();
      
      cola.pop( );
      
      if (distancias[procesar.vertice] == -1) {
         
         distancias[procesar.vertice] = procesar.distancia;

         for (auto vecino : adyacencia[procesar.vertice]) {
            cola.push( registro{vecino.vertice, vecino.longitud + procesar.distancia, procesar.cupon_valido } );
            if ( procesar.cupon_valido ) {
            	cola.push( registro{vecino.vertice, procesar.distancia, false } );
            }
         }
      }
    }

    cout << distancias[ n - 1 ] << '\n';
    //for (int i = 0; i < n; ++i) { cout << i << ": " << distancias[i] << "\n";}
}