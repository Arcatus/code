#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <climits>
#include <set>
#include <map>

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

bool operator<(const arista& r1, const arista& r2) {
   return r1.costo > r2.costo;
}

int main( ) 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;

	vector< vecino > adyacencia[n];

   priority_queue< arista > aristas;

	for (int i = 0; i < m; ++i) {
      int x, y, c;
      std::cin >> x >> y >> c;
      adyacencia[x].push_back(vecino{y, c});
      adyacencia[y].push_back(vecino{x, c});
      aristas.push( arista{ min(x,y),max(x,y), c });
   }

   int distancias[n];

   int ans = INT_MAX;

   while ( aristas.size() > 0 ) {
   
     	priority_queue<registro> cola;

      cola.push( registro{ 0, 0 } );

      fill( distancias, distancias + n, -1);

      arista toDelete = aristas.top();
      aristas.pop();

     	while ( !cola.empty() ) {
         
         registro procesar = cola.top();
         cola.pop();
         
         if (distancias[procesar.vertice] == -1) {
            
            distancias[procesar.vertice] = procesar.distancia;

            for (auto vecino : adyacencia[procesar.vertice]) {
               if ( toDelete.origen == procesar.vertice && toDelete.destino == vecino.vertice ) {
                  cola.push(
                     registro{ vecino.vertice, 0 + procesar.distancia });
               } else {
                  cola.push(
                     registro{ vecino.vertice, vecino.longitud + procesar.distancia });
               }
            }
         }
       }
       ans = min( ans, distancias[n-1] );
   }
   cout << ans << '\n';
}
