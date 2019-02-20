#include <cstdint>
#include <iostream>
using namespace std;

// el resultado de la siguiente recurrencia crece muy rapido
// el tipo de retorno puede ser unsigned long long para poder calcular algunos resultados que en un int ya no caben

unsigned long long recurrencia(int n)
// asunción: n es no negativo
{
   if (n <= 1) {
      return 1;
   } else {
      return recurrencia(n - 1) * 3 + 5;
   }
}

unsigned long long recurrencia_lento(int n)
// asunción: n es no negativo; el trabajo repetido es obvio en comparación con la versión de arriba
{
   if (n <= 1) {
      return 1;
   } else {
      return recurrencia(n - 1) + recurrencia_lento(n - 1) + recurrencia_lento(n - 1) + 5;
   }
}

int main( )
{
   for (int i = 0; i <= 35; ++i) {
      cout << i << ": " << recurrencia(i) << " vs " << recurrencia_lento(i) << "\n";
   }
}
