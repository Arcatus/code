#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

struct vecino {
   int vertice, longitud;
};

struct registro {
   int vertice, distancia;
};

bool operator<(const registro& r1, const registro& r2) {
   return r1.distancia > r2.distancia;
}

int main( ) {
   int n, m;
   std::cin >> n >> m;

   std::vector<vecino> adyacencia[n];

   for (int i = 0; i < m; ++i) {
      int x, y, c;
      std::cin >> x >> y >> c;
      adyacencia[x].push_back(vecino{y-1, c});
      adyacencia[y].push_back(vecino{x-1, c});
   }

   int distancias[n]; 
   std::fill_n(&distancias[0], n, -1);
   std::priority_queue<registro> cola;
   cola.push(registro{0, 0});

   while (!cola.empty( )) {
      registro procesar = cola.top( );
      cola.pop( );
      if (distancias[procesar.vertice] == -1) {
         distancias[procesar.vertice] = procesar.distancia;
         for (auto vecino : adyacencia[procesar.vertice]) {
            cola.push(registro{vecino.vertice, vecino.longitud + procesar.distancia});
         }
   }

   for (int i = 0; i < n; ++i) {
      std::cout << i << ": " << distancias[i] << "\n";
   }
}
