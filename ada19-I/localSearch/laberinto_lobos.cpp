// https://omegaup.com/arena/problem/lsp/#problems
#include <limits.h>
#include <iostream>
#include <vector>

struct posicion {
   int f, c;
};

struct posicion_anotada {
   int f, c, w;
};

int main( ) {
   int lobos, n;
   std::cin >> lobos >> n;

   char tablero[n][n];
   
   posicion entrada, salida;

   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         std::cin >> tablero[i][j];
         if (tablero[i][j] == 'E') {
            entrada = { i, j };
         } else if (tablero[i][j] == 'S') {
            salida = { i, j };
         }
      }
   }

   int registro[n][n];
   
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         registro[i][j] = INT_MAX;
      }
   }

   std::vector<posicion_anotada> actual = {
      { entrada.f, entrada.c, 0 }
   };
   registro[entrada.f][entrada.c] = 0;

   for (int p = 0; !actual.empty( ); ++p) {
      std::vector<posicion_anotada> siguiente;
      for (posicion_anotada procesar : actual) {
         if (procesar.f == salida.f && procesar.c == salida.c) {
            std::cout << p << "\n";
            return 0;
         }

         posicion checar[4] = {
            { procesar.f - 1, procesar.c },
            { procesar.f + 1, procesar.c },
            { procesar.f, procesar.c - 1 },
            { procesar.f, procesar.c + 1 }
         };
         for (posicion vecino : checar) {
            if (0 <= vecino.f && vecino.f < n &&
                0 <= vecino.c && vecino.c < n &&
                tablero[vecino.f][vecino.c] != '#') {
               posicion_anotada nueva = {
                  vecino.f,
                  vecino.c,
                  procesar.w + (tablero[vecino.f][vecino.c] == '*')
               };
               if (nueva.w <= lobos &&
                   nueva.w < registro[vecino.f][vecino.c]) {
                  siguiente.push_back(nueva);
                  registro[vecino.f][vecino.c] = nueva.w;
               }
            }
         }
      }
      actual = siguiente;
   }

   std::cout << -1 << "\n";
}

