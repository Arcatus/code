#include <iostream>
// Contaremos cuántos recorridos del caballo
// existen si no necesitamos regresar a la celda
// inicial y la celda inicial la podemos elegir

int n;
int faltan;
bool visitado[8][8] = { };

int cuenta(int f, int c) {
   if (faltan == 0) {
      return 1;
   }

   int destinos[8][2] = {
      { f - 2, c - 1 },
      { f - 2, c + 1 },
      { f - 1, c - 2 },
      { f - 1, c + 2 },
      { f + 2, c - 1 },
      { f + 2, c + 1 },
      { f + 1, c - 2 },
      { f + 1, c + 2 },
   };

   int res = 0;
   for (int i = 0; i < 8; ++i) {
      if (0 <= destinos[i][0] && destinos[i][0] < n &&
          0 <= destinos[i][1] && destinos[i][1] < n &&
          !visitado[destinos[i][0]][destinos[i][1]]) {
         
         visitado[destinos[i][0]][destinos[i][1]] = true;
         faltan -= 1;
         res += cuenta(destinos[i][0], destinos[i][1]);
         faltan += 1;
         visitado[destinos[i][0]][destinos[i][1]] = false;
      }
   }
   return res;
}

int main( ) {
   std::cin >> n;

   faltan = n * n;
   int res = 0;
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         visitado[i][j] = true;
         faltan -= 1;
         res += cuenta(i, j);
         faltan += 1;
         visitado[i][j] = false;
      }
   }

   std::cout << res << "\n";
}
