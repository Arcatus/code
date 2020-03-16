#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <climits>
#include <set>

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
   fill(distancias, distancias+n, INT_MAX);

   bool reached[n];
   fill(reached, reached+n, false);

   priority_queue< registro > micola;

   micola.push( registro{ 0, 0, true } );

   while( !micola.empty() ) {
      registro v = micola.top();
      micola.pop();

      if ( v.vertice == n - 1 ) {
         cout << v.distancia << '\n';
         return 0;
      }

      if ( distancias[v.vertice] == INT_MAX  || (v.cupon_valido && !reached[v.vertice] ) ) {
         
         if ( v.cupon_valido ) {
            reached[v.vertice] = true;
         }

         distancias[v.vertice] = min(v.distancia,distancias[v.vertice]);

         for( vecino p : adyacencia[v.vertice] ) {
            if ( v.cupon_valido ) {
               micola.push( registro{ p.vertice, v.distancia, false} );
            }
            if ( !v.cupon_valido && v.distancia + p.longitud > distancias[p.vertice] ) {
               continue;
            }
            micola.push( registro{ p.vertice, v.distancia + p.longitud, v.cupon_valido } );

         } 
      }
   }
   cout << -1 << '\n';
}