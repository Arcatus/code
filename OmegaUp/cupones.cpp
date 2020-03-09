#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits.h>
#include <set>

using namespace std;

struct vecino {
   int vertice, longitud;
};

struct registro {
   int vertice, distancia;
   bool cupon_valido;
   set<int> path;
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
      set<int> p;
   	cola.push( registro{ 0, 0, true, p } );

      int pass[n];
      fill( pass, pass + n, 0);   

   	while ( !cola.empty() ) {

      registro procesar = cola.top();

      cola.pop();
      
      if ( distancias[procesar.vertice] == -1  ||
             (procesar.distancia > distancias[procesar.vertice]) && procesar.cupon_valido ) {
         //cerr << "procesar vertice: " << procesar.vertice << " procesar distancia: "<< procesar.distancia << '\n';
         
         if ( distancias[procesar.vertice] != -1 )
            distancias[procesar.vertice] = min(procesar.distancia,distancias[procesar.vertice]);
         else 
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
}