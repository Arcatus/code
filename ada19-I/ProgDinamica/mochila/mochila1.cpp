// El problema de la mochila (backtracking): capacidad y ganancias como globales

#include <algorithm>
#include <stdio.h>
using namespace std;

int n;
int capacidad;
int objetos[40];

int mejor_carga = 0;
int carga_actual = 0;

void resuelve(int i) {
   if (i == n) {
      mejor_carga = max(mejor_carga, carga_actual);
      return;
   }

   resuelve(i + 1);
   if (objetos[i] <= capacidad) {
      capacidad -= objetos[i];
      carga_actual += objetos[i];
      resuelve(i + 1);
      carga_actual -= objetos[i];
      capacidad += objetos[i];
   }
}

int main( ) {
   scanf("%d%d", &n, &capacidad);
   for (int i = 0; i < n; ++i) {
      scanf("%d", &objetos[i]);
   }

   resuelve(0);
   printf("%d\n", mejor_carga);
}
