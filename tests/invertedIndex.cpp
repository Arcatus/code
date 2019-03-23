
#include <iostream>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::string;
using std::lower_bound;

string s;

int t[128] = { };

int pos_lista[128] = { };

int i, n, a, b;
int *left;
char z;

int main( )
{	
   std::ios_base::sync_with_stdio(false);

   cin >> s;

   n = s.length();

   for (i = 0; i < n; ++i)
   {
      ++t[s[i]];
   }

   int* filas[128];

   for (i = 48; i < 58; ++i) {
      filas[i] = new int[t[i]];
   }

   for (i = 65; i < 91; ++i) {
      filas[i] = new int[t[i]];
   }

   for (i = 97; i < 123; ++i) {
      filas[i] = new int[t[i]];
   }

   
   for (i = 0; i < n; ++i) {
      filas[s[i]][pos_lista[s[i]]++] = i;
   }

   cin >> n;

   for (i = 0; i < n; ++i)
   {
   		cin >> z >> a >> b;

   		b = b - 1 + a;
		
		left  = lower_bound( 
			&filas[z][0], &filas[z][t[z]], a);
   			
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

