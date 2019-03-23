#include <stdio.h>

enum eventos {
   BOLA = 0,
   TACHE = 1,
   VACIO = 2,
   EMPATE = 2,
   INDEFINIDO
};

struct tablero {
   int mem[3][3];
};

tablero pon_jugada(tablero t, int i, int j, int jugador) {
   t.mem[i][j] = jugador;
   return t;
}

int ganador(tablero t) {
   for (int i = 0; i < 3; ++i) {
      if (t.mem[i][0] != VACIO &&
          t.mem[i][0] == t.mem[i][1] && t.mem[i][1] == t.mem[i][2]) {
         return t.mem[i][0];
      }

      if (t.mem[0][i] != VACIO &&
          t.mem[0][i] == t.mem[1][i] && t.mem[1][i] == t.mem[2][i]) {
         return t.mem[0][i];
      }
   }

   if (t.mem[1][1] != VACIO && (
       t.mem[0][0] == t.mem[1][1] && t.mem[1][1] == t.mem[2][2] ||
       t.mem[0][2] == t.mem[1][1] && t.mem[1][1] == t.mem[2][0])) {
      return t.mem[1][1];
   }

   for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
         if (t.mem[i][j] == VACIO) {
            return INDEFINIDO;
         }
      }
   }

   return EMPATE;
}

int oponente(int jugador) {
   return !jugador;
}

int preferente(int jugador, int r1, int r2) {
   if (r1 == jugador || r2 == jugador) {
      return jugador;
   }
   if (r1 == EMPATE || r2 == EMPATE) {
      return EMPATE;
   }
   return oponente(jugador);
}

int minimax(tablero t, int jugador) {
   int g = ganador(t);
   if (g != INDEFINIDO) {
      return g;
   }

   int mejor = oponente(jugador);
   for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
         if (t.mem[i][j] == VACIO) {
            tablero p = pon_jugada(t, i, j, jugador);
            mejor = preferente(jugador, mejor, minimax(p, oponente(jugador)));
         }
      }
   }

   return mejor;
}

int main( ) {
   tablero t;
   for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
         t.mem[i][j] = VACIO;
      }
   }

   printf("%d\n", minimax(t, BOLA));
}
