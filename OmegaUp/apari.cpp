#include <iostream>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::string;
using std::lower_bound;

string s;

int cuentas[128] = { };

int pos_lista[128] = { };

int i;
int n;
int *left;
int apariciones;
int preguntas;
char a_buscar;
int a, b;
int selection;

int main( )
{	
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(0);
   cin >> s;

   n = s.length();

   for (i = 0; i < n; ++i)
   {
      cuentas[s[i]] += 1;
   }

   int* filas[128];

   for (i = 48; i < 58; ++i) {
      filas[i] = new int[cuentas[i]];
   }

   for (i = 65; i < 91; ++i) {
      filas[i] = new int[cuentas[i]];
   }

   for (i = 97; i < 123; ++i) {
      filas[i] = new int[cuentas[i]];
   }

   
   for (int i = 0; i < n; ++i) {
      filas[s[i]][pos_lista[s[i]]++] = i;
   }

   cin >> preguntas;

   for (i = 0; i < preguntas; ++i)
   {
   		cin >> a_buscar >> a >> b;

   		b = b - 1 + a;

   		apariciones = cuentas[a_buscar];

   		if ( apariciones == 0)
   		{
   			cout << "0\n";
   		}
   		else if ( apariciones == 1 )
   		{
   			selection = filas[a_buscar][0];

   			if ( a <= selection && selection <= b  )
	   		{
	   			cout << "1\n";
	   		}
	   		else
	   		{
	   			cout << "0\n";
	   		}
   		}
   		else
   		{   			

   			left  = lower_bound( &filas[a_buscar][0], &filas[a_buscar][ apariciones ], a);
   			
			if ( a <= *left && *left <= b )
 			{
 				cout << "1\n";
 			}
 			else
 			{
				cout << "0\n";
 			}
   		}

   }
}