// ordenamiento de una cantidad fija de elementos
#include <algorithm>
#include <iostream>
using namespace std;

// sort2 ordena a, b de modo que el valor más pequeño queda en a y el valor más grande queda en b
void sort2(int& a, int& b)
{
   if (b < a) {
      swap(a, b);
   }
}

void sort3(int& a, int& b, int& c)
{
   sort2(a, b);      // después de las primeras dos invocaciones a sort2, sabemos que el elemento
   sort2(b, c);      // más grande fue arrastrado hacia c, pero no sabemos cómo quedaron a, b
   sort2(a, b);      // aquí los ordenamos por si no lo estaban
}

void sort4(int& a, int& b, int& c, int& d)
{
   sort2(a, b);      // después de las tres invocaciones a sort2, sabemos que el elemento
   sort2(b, c);      // más grande fue arrastrado hacia d, pero no sabemos cómo quedaron a, b, c
   sort2(c, d);
   sort3(a, b, c);   // aquí los ordenamos por si no lo estaban
}                    // este algoritmo hizo un total de seis invocaciones a sort2 (tres directas, tres en sort3)

void sort4_torneo(int& a, int& b, int& c, int& d)
{
   sort2(a, b);      // compiten a, b y el más grande queda en b
   sort2(c, d);      // compiten c, d y el más grande queda en d
   sort2(b, d);      // (ganador VS ganador) compiten b, d y el más grande de los cuatro números queda en d
   sort2(a, c);      // (perdedor VS perdedor) compiten a, c y el más pequeño de los cuatro números queda en a
   sort2(b, c);      // (perdedor de los ganadores VS ganador de los perdedores) ordenamos los que no son ni el menor ni el mayor
}                    // este algoritmo hizo un total de cinco invocaciones a sort2

int main( )
{
   {
      int a = 2, b = 1;
      sort2(a, b);
      cout << "sort2: " << a << " " << b << "\n";
   }

   {
      int a = 3, b = 1, c = 2;
      sort3(a, b, c);
      cout << "sort3: " << a << " " << b << " " << c << "\n";
   }

   {
      int a = 3, b = 1, c = 4, d = 2;
      sort4(a, b, c, d);
      cout << "sort4: " << a << " " << b << " " << c << " " << d << "\n";
   }

   {
      int a = 3, b = 1, c = 4, d = 2;
      sort4_torneo(a, b, c, d);
      cout << "sort4_torneo: " << a << " " << b << " " << c << " " << d << "\n";
   }
}


