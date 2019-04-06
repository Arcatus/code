// el operador new pide memoria del almacenamiento libre; la memoria del almacenamiento libre no se libera hasta que se hace delete a un apuntador que apunte a ella
// se puede pedir una variable o un arreglo de variables; en ambos casos, el operador devuelve la dirección de la memoria asignada (es decir, un apuntador a ella)
#include <iostream>
using namespace std;

int main( )
{
   int* p1 = new int;               // pidiendo memoria para un int en el almacenamiento libre
   int* p2 = new int[10000000];     // pidiendo memoria para un arreglo de ints en el almacenamiento libre
                                    // el almacenamiento libre en principio no tiene límite, a diferencia de la pila del proceso que usualmente tiene un límite entre 1MB y 8MB

   *p1 = 57;                                 // escribimos en la variable individual
   for (int i = 0; i < 10000000; ++i) {
      p2[i] = 57;                            // escribimos en los elementos del arreglo, recuerden que *(p2 + i) es equivalente a p2[i]
   }

   delete p1;                       // liberando la memoria del int individual
   delete[] p2;                     // liberando la memoria del arreglo de ints

   {
      int* r = new int[100000];     // pidiendo memoria para un arreglo de ints en el almacenamiento libre, su dirección la guardamos en la variable local r
   }                                // el apuntador r muere (es una variable local) pero la memoria del almacenamiento libre sigue asignada
                                    // como ya perdimos el apuntador a ella, ya no podremos hacerle delete y no podremos liberarla
}
