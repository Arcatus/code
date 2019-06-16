// El problema de la mochila (backtracking): ganancias como globales
#include <algorithm>
#include <stdio.h>
using namespace std;

int n;
int objetos[40];

int mejor_carga = 0;
int carga_actual = 0;

void resuelve(int i, int c) {
   if (i == n) {
      mejor_carga = max(mejor_carga, carga_actual);
      return;
   }

   resuelve(i + 1, c);
   if (objetos[i] <= c) {
      carga_actual += objetos[i];
      resuelve(i + 1, c - objetos[i]);
      carga_actual -= objetos[i];
   }
}

int main( ) {
   int capacidad;
   scanf("%d%d", &n, &capacidad);
   for (int i = 0; i < n; ++i) {
      scanf("%d", &objetos[i]);
   }

   resuelve(0, capacidad);
   printf("%d\n", mejor_carga);
}
