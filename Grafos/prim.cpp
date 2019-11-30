#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

struct vecino {
   int vertice, longitud;
};

struct registro {
   int vertice, costo;
};

bool operator<(const registro& r1, const registro& r2) {
   return r1.costo > r2.costo;
}

int main( ) {
   int n, m;
   std::cin >> n >> m;

   std::vector<vecino> adyacencia[n];
   for (int i = 0; i < m; ++i) {
      int x, y, c;
      std::cin >> x >> y >> c;
      adyacencia[x-1].push_back(vecino{y-1, c});
      adyacencia[y-1].push_back(vecino{x-1, c});
   }

   int costos[n];
   std::fill_n(&costos[0], n, -1);
   std::priority_queue<registro> cola;
   cola.push(registro{0, 0});

   while (!cola.empty( )) {
      registro procesar = cola.top( );
      cola.pop( );
      if (costos[procesar.vertice] == -1) {
         costos[procesar.vertice] = procesar.costo;
         for (auto vecino : adyacencia[procesar.vertice]) {
            cola.push(registro{vecino.vertice, vecino.longitud});
         }
      }
   }

   std::cout << std::accumulate(&costos[0], &costos[0] + n, 0) << "\n";
}
