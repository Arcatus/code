#include <iostream>

using namespace std;

int main( )
{
   int t, r;
   cin >> t >> r;

   int velas_disponibles = t;

   float velas_creadas = 0.0f;
   
   int horas = 0;

   while( velas_disponibles > 0)
   {
	   	horas++;
   		velas_disponibles--;
   		velas_creadas += 1.0f/float(r);

   		if (velas_creadas >= 0.99999f)
   		{
   			velas_disponibles++;
   			velas_creadas = velas_creadas - 0.99999f;
   		}
   }
   cout << horas << '\n';
}