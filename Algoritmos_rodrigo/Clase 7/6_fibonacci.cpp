#include <cstdint>
#include <iostream>
using namespace std;

// el resultado de la siguiente recurrencia crece muy rapido
// el tipo de retorno puede ser unsigned long long para poder calcular algunos resultados que en un int ya no caben

unsigned long long fibonacci(int n)
// asunción: n es no negativo; el trabajo repetido no es obvio pero también ocurre tal como vimos en clase
{
   if (n <= 1) {
      return n;
   } else {
      return fibonacci(n - 1) + fibonacci(n - 2);
   }
}

int main( )
{
   for (int i = 0; i <= 50; ++i) {
      cout << i << ": " << fibonacci(i) << "\n";
   }
}
