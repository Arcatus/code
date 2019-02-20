// uso básico de referencias
#include <iostream>
using namespace std;

int main( )
{
   int n = 5;
   int& r = n;

   cout << n << " " << r << "\n";
   r = 7;
   cout << n << " " << r << "\n";
}
