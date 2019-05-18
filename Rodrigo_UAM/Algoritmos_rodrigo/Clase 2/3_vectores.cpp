// https://omegaup.com/arena/problem/Suma-de-vectores/#problems
#include <iostream>
using namespace std;

int main( )
{
   int n;
   cin >> n;
   int v[n];

   for (int i = 0; i < n; ++i) {
      cin >> v[i];
   }

   for (int i = 0; i < n; ++i) {
      int temp;
      cin >> temp;
      cout << v[i] + temp << " ";
   }
}
