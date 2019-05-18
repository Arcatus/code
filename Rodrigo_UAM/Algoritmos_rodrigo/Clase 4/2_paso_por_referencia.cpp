// paso por referencia: la funci�n no trabaja sobre una copia, por lo que las modificaciones s� se reflejan en el llamante
#include <iostream>
using namespace std;

void swap(int& a, int& b)     // funci�n para intercambiar dos valores, std::swap ya existe en <algorithm>
{
   int temp = a;
   a = b;
   b = temp;
}

int main( )
{
   int a, b;
   cin >> a >> b;
   swap(a, b);

   cout << a << " " << b << "\n";
}
