// paso por valor: la función trabaja sobre una copia, por lo que las modificaciones no se reflejan en el llamante
#include <iostream>
using namespace std;

int digitos10(int n)
{
   int d = 0;
   do {
      n /= 10;
      d += 1;
   } while (n != 0);

   return d;
}

int main( )
{
   int n;
   cin >> n;
   int d = digitos10(n);

   cout << n << ": " << d << " digito(s) en decimal\n";
}
