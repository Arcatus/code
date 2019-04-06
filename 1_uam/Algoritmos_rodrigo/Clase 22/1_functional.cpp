// Este programa hace uso de los objetos función de la biblioteca estándar de C++ para realizar ordenamientos
// Estos objetos función son útiles para personalizar algunas estructuras de datos que guardan sus elementos según el resultado de las comparaciones entre los mismos
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

template<typename T>
void imprime(const vector<T>& v)
{
   cout << "{ ";
   for (const auto& actual : v) {
      cout << actual << " ";
   }
   cout << "}\n";
}

int main( )
{
   vector<int> v = { 3, 1, 4, 1, 5, 9, 2 };

   // ordenando de menor a mayor de diferentes maneras
   sort(v.begin( ), v.end( ));                           // el ordenamiento por omisión es de menor a mayor
   imprime(v);
   sort(v.begin( ), v.end( ), [](int a, int b) {         // devolvemos verdadero si a debe ir antes que b
      return a < b;                                      // queremos que vaya antes si es más pequeño
   });
   imprime(v);
   less<int> cmp1;                                       // less<T> hace uso del operador < cuando se le pide comparar dos elementos
   sort(v.begin( ), v.end( ), cmp1);                     // pasamos el comparador a sort
   imprime(v);
   sort(v.begin( ), v.end( ), less<int>( ));             // forma abreviada usando un temporal

   // ordenando de mayor a menor usando diferentes expresiones
   sort(v.begin( ), v.end( ), [](int a, int b) {         // devolvemos verdadero si a debe ir antes que b
      return a > b;                                      // queremos que vaya antes si es más grande
   });
   imprime(v);
   greater<int> cmp2;                                    // greater<T> hace uso del operador > cuando se le pide comparar dos elementos
   sort(v.begin( ), v.end( ), cmp2);                     // pasamos el comparador a sort
   imprime(v);
   sort(v.begin( ), v.end( ), greater<int>( ));          // forma abreviada usando un temporal
}
