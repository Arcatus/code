// este programa ejemplifica varias funciones de vector, que es un arreglo de tamaño redimensionable
#include <algorithm>
#include <iostream>
#include <vector>                            // debemos incluir <vector> para poder usar este tipo de dato
using namespace std;

void imprime(const vector<int>& v)           // paso por referencia a const; si pasamos por valor estaríamos haciendo una copia del vector completo y realmente no necesitamos hacer eso
{                                            // pasamos por referencia para evitar la copia y por const para indicar que no necesitamos modificarlo, solo leerlo
   cout << "{ ";
   for (int i = 0; i < v.size( ); ++i) {
      cout << v[i] << " ";
   }
   cout << "} \n";
}

int main( )
{
   vector<int> v = { 5, 2, 9 };        // podemos inicializar el vector con una secuencia
   imprime(v);
   v.push_back(6);                     // agregamos un elemento al final del vector
   imprime(v);
   v.pop_back( );                      // quitamos el último elemento
   imprime(v);
   v.clear( );                         // vaciamos el vector
   imprime(v);
   v.resize(7);                        // redimensionamos el vector, los nuevos elementos se llenan con 0
   imprime(v);
   v.resize(10, -1);                    // redimensionamos el vector, los nuevos elementos se llenan con -1
   imprime(v);
   v.resize(8);                        // redimensionamos el vector (en este caso, lo achicamos)
   imprime(v);

   cout << "tam: " << v.size( ) << "\n";                 // número de elementos que tiene guardados el vector
   cout << "capacidad: " << v.capacity( ) << "\n";       // capacidad que tiene el vector; conforme va creciendo a veces pide más memoria que la estrictamente necesaria
}
