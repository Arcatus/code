// uso de memoria y rangos de tipos de datos
#include <climits>
#include <iostream>
using namespace std;

int main( )
{
   // asumiremos que un char siempre ocupa 8 bits (un byte)
   cout << "El numero de bytes en un char es: " << sizeof(char) << "\n";
   cout << "El numero de bytes en un int es: " << sizeof(int) << "\n";
   cout << "Los valores minimo y maximo de un int son: " << INT_MIN << " " << INT_MAX << "\n";
   cout << "El valor maximo de un unsigned int es: " << UINT_MAX << "\n";
}
