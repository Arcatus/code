// https://sites.google.com/site/rccuam/home/1151042---algoritmos-y-estructuras-de-datos
#include <iostream>
using namespace std;

int main( )
{
   int n;
   cin >> n;

   int v = 1, e = 0;
   while (v != n) {
      v *= 2;
      e += 1;
   }

   cout << e;
}
