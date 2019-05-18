// programa que ejemplifica el uso de referencias en el for de rango
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main( )
{
   vector<string> v = { "hola", "como", "estan", "gatito", "perrito", "adios" };

   for (string s : v) {                // s es una copia del elemento de v que estamos visitando
      s = "CAMBIO";                    // modificamos s pero como es una copia, el elemento en v no se modifica
   }
   for (string s : v) {                // volvemos a iterar
      cout << s << " ";                // siguen los valores originales
   }
   cout << "\n";

   for (string& s : v) {               // s es el elemento real de v que estamos visitando, no estamos haciendo una copia
      s = "CAMBIO";                    // modificamos s, el elemento en v sí se modifica
   }
   for (const string& s : v) {         // volvemos a iterar con referencias a const (para evitar hacer una copia y para indicar que no queremos modificar el elemento de v)
      cout << s << " ";                // en el ciclo anterior sí se modificaron los elementos de v
   }
   cout << "\n";
}
