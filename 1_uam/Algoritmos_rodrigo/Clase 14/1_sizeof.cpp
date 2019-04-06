// el operador sizeof devuelve el número de bytes que usa una variable, pero sin incluir la memoria usada por sus partes remotas (memoria a la que apuntan)
#include <iostream>
#include <vector>
using namespace std;

int main( )
{
   int* p = nullptr;             // apuntador que no apunta a nada
   cout << sizeof(p) << "\n";    // bytes que ocupa el apuntador
   p = new int[1000];            // apuntador que apunta a 1000 enteros apartados con memoria dinámica
   cout << sizeof(p) << "\n";    // bytes que ocupa el apuntador (no se incluye los bytes de la memoria apuntada)
   delete[] p;                   // liberando la memoria apuntada por p
   cout << "\n";

   vector<int> v;                // un vector vacío
   /*
      template<typename T>
      struct vector {
         T* mem;        // un apuntador
         size_t tam;    // un entero sin signo capaz de representar cualquier tamaño de memoria
         size_t cap;    // un entero sin signo capaz de representar cualquier tamaño de memoria
      };
   */
   cout << sizeof(v) << "\n";    // bytes que ocupa un vector
   v.resize(1000);               // apartando memoria para 1000 enteros
   cout << sizeof(v) << "\n";    // bytes que ocupa el apuntador (no se incluye los bytes de la memoria apuntada)
}
