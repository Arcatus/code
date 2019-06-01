#include <iostream>

enum estado {
   BOLA = 0, TACHE = 1, EMPATE, INDEFINIDO
};

struct tablero {
   int mem[3][3];
};

int ganador(tablero t) {
   for (int j = 0; j <= 1; ++j) {
      for (int i = 0; i < 3; ++i) {
         if (t.mem[i][0] == j && t.mem[i][1] == j && t.mem[i][2] == j) {
            return j;
         }
         if (t.mem[0][i] == j && t.mem[1][i] == j && t.mem[2][i] == j) {
            return j;
         }
      }
      if (t.mem[1][1] == j) {
         if (t.mem[0][0] == j && t.mem[2][2] == j) {
            return j;
         }
         if (t.mem[0][2] == j && t.mem[2][0] == j) {
            return j;
         }
      }
   }

   for (int f = 0; f < 3; ++f) {
      for (int c = 0; c < 3; ++c) {
         if (t.mem[f][c] == INDEFINIDO) {
            return INDEFINIDO;
         }
      }
   }

   return EMPATE;
}

int oponente(int j) {
   return !j;
}

tablero pon_jugada(tablero t, int f, int c, int j) {
   t.mem[f][c] = j;
   return t;
}

int mejor_resultado(int g1, int g2, int j) {
   if (g1 == j || g2 == j) {
      return j;
   } else if (g1 == EMPATE || g2 == EMPATE) {
      return EMPATE;
   } else {
      return oponente(j);
   }
}

int oraculo(int j, tablero t) {
   int g = ganador(t);
   if (g != INDEFINIDO) {
      return g;
   }

   g = oponente(j);
   for (int f = 0; f < 3; ++f) {
      for (int c = 0; c < 3; ++c) {
         if (t.mem[f][c] == INDEFINIDO) {
            int gp = oraculo(oponente(j), pon_jugada(t, f, c, j));
            g = mejor_resultado(g, gp, j);
         }
      }
   }

   return g;
}

int main( ) {
   tablero t;
   for (int f = 0; f < 3; ++f) {
      for (int c = 0; c < 3; ++c) {
         t.mem[f][c] = INDEFINIDO;
      }
   }

   std::cout << oraculo(0, t) << "\n";
}
