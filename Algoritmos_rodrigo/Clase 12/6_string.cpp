// este programa muestra el uso básico de string, que es una cadena de tamaño redimensionable
#include <algorithm>
#include <iostream>
#include <string>                                     // deben incluir <string> para poder usar este tipo de dato
using namespace std;

int main( )
{
   cout << "dame una palabra de cualquier longitud: ";
   string s;
   cin >> s;                                          // aparta tanta memoria como necesite conforme va leyendo
   cout << "la palabra que me diste es " << s << " y tiene " << s.size( ) << " caracteres\n";
                                                      // no pueden leer un string redimensionable de C++ usando scanf, deben usar cin
   for (int i = 0; i < s.size( ); ++i) {
      cout << "[" << i << "]: " << s[i] << "\n";      // pueden acceder a sus elementos como si fuera un arreglo
   }
}
