// tiempo de vida de las variables automaticas
#include <iostream>
using namespace std;

int main( )
{
   {
      int n;
      cout << "n vive en " << &n << "\n";
   } // al llegar aquí, n deja de existir y su memoria se libera

   {
      int m;
      cout << "m vive en " << &m << "\n";
   } // al llegar aquí, m deja de existir y su memoria se libera

   int n;
   cout << "la nueva n vive en " << &n << "\n";
   int m;
   cout << "la nueva m vive en " << &m << "\n";
}
