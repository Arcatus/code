// paso por referencia a const: no se trabaja sobre una copia pero también se indica que no tenemos intención de hacer modificaciones
#include <iostream>
using namespace std;

struct fecha {
   int dia;
   int mes;
   int anyo;
};

bool menor(const fecha& f1, const fecha& f2)
{
   if (f1.anyo != f2.anyo) {
      return f1.anyo < f2.anyo;
   } else if (f1.mes != f2.mes) {
      return f1.mes < f2.mes;
   } else {
      return f1.dia < f2.dia;
   }

   // lo siguiente no compilaría (f1 es const)
   // f1.dia = 15;
}

int main( )
{
   fecha f1 = { 5, 6, 2009 };
   fecha f2 = { 28, 11, 2017 };
   cout << menor(f1, f2);
}
