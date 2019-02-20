// este programa lee enteros, uno tras otro, hasta que encuentra un error o hasta que se acaba la entrada
// se puede indicar el fin de la entrada desde la consola con CTRL+Z (en Windows) o se puede redirigir la entrada para leerla desde un archivo usando la línea de comandos
#include <iostream>
using namespace std;

int main( )
{
   int n;
   while (cin >> n) {
      cout << "leimos el entero " << n << "\n";
   }
}
