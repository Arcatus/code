// equal_range devuelve una pareja con el resultado de lower_bound y upper_bound; usualmente es más rápido que llamar a ambas funciones de manera individual
#include <algorithm>
#include <iostream>
#include <utility>      // aquí se declara pair<T1, T2>
using namespace std;

int main( )
{
   int arr[7] = { 1, 4, 4, 4, 8, 10, 10 };

   pair<int*, int*> r = equal_range(&arr[0], &arr[7], 4);
   cout << "hay " << r.second - r.first << " elementos que valen 4\n";
   for (int* p = &arr[0]; p < r.first; ++p) {
      cout << *p << " <, ";
   }
   for (int* p = r.first; p < r.second; ++p) {
      cout << *p << " ==, ";
   }
   for (int* p = r.second; p < &arr[7]; ++p) {
      cout << *p << " >, ";
   }
   cout << "\n";
}
