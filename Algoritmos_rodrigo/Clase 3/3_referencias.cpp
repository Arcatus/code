// uso de referencias como par�metros de funci�n
#include <iostream>
using namespace std;

void f(int& r)
{
   r += 1;
}

int main( )
{
   int n = 5;
   f(n);
   cout << n << "\n";
}
