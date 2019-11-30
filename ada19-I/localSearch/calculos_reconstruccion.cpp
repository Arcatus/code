//https://omegaup.com/arena/problem/OIEG2013SSA#problems
#include <iostream>
#include <vector>

int main( ) {
   int a, b, n;
   std::cin >> a >> b >> n;

   int registro[10000];
   for (int i = 0; i < 10000; ++i) {
      registro[i] = -1;
   }
   std::vector<int> actual = { 1 };
   registro[1] = -2;

   for (int p = 0; ; ++p) {
      std::vector<int> siguiente;
      for (int procesar : actual) {
         if (procesar == n) {
            std::cout << p << "\n";
            std::vector<int> ruta;
            do {
               ruta.push_back(n);
               n = registro[n];
            } while (n != -2);
            for (int i = ruta.size( ) - 1; i >= 0; --i) {
               std::cout << ruta[i] << " ";
            }
            return 0;
         }

         if (procesar * a <= 9999 && registro[procesar * a] == -1) {
            siguiente.push_back(procesar * a);
            registro[procesar * a] = procesar;
         }
         if (procesar / b <= 9999 && registro[procesar  / b] == -1) {
            siguiente.push_back(procesar / b);
            registro[procesar / b] = procesar;
         }
      }
      actual = siguiente;
   }
}
