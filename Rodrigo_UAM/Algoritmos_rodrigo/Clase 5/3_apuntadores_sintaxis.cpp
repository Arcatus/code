// apuntadores y aspectos sintácticos
#include <iostream>
using namespace std;

int main( )
{
   int arr[7] = { };
   int* p = &arr[2];    // desplazamiento dos elementos con respecto al inicio
   p[3] = 1000;         // desplazamiento tres elementos con respecto al apuntador

   for (int i = 0; i < 7; ++i) {
      cout << "Posicion " << i << ": " << arr[i] << "\n";
   }
}
