// apuntadores y aspectos sintácticos
#include <iostream>
using namespace std;

struct fecha {
   int dia;
   int mes;
   int anyo;
};

int main( )
{
   fecha f = { 1, 2, 1900 };

   fecha g;
   g.dia = 1;
   g.mes = 2;
   fecha* p = &g;
   (*p).anyo = 1900;
   p->anyo = 1900;

   cout << f.dia << " " << f.mes << " " << f.anyo << "\n";
   cout << g.dia << " " << g.mes << " " << g.anyo << "\n";
}
