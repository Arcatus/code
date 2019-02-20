// ejemplo de implementación de push_back usando memoria dinámica
#include <algorithm>
#include <iostream>
using namespace std;

template<typename T>
struct mi_vector {
   T* mem = nullptr;             // apuntador al bloque de memoria, inicialmente no tenemos memoria
   int tam = 0;                  // número de elementos que hemos guardado
   int cap = 0;                  // número de elementos que caben en el bloque que tenemos
};

template<typename T>
void push_back(mi_vector<T>& v, const T& agregar)           // agregar un nuevo elemento al vector
{                                         // la función tiene un bug, pero está bastante escondido :) siempre prefieran usar el de la biblioteca
   if (v.mem == nullptr) {                // no tenemos memoria
      v.mem = new T[1];                      // pedimos memoria para un arreglo de un elemento
      v.cap = 1;                             // ya tenemos capacidad para un elemento
   } else if (v.tam == v.cap) {           // sí tenemos memoria pero ya está llena (estamos usando toda la capacidad que tenemos y no hay espacio para el nuevo elemento)
      T* nuevo = new T[2 * v.cap];           // pedimos memoria para un bloque con el doble de capacidad
      copy_n(v.mem, v.tam, nuevo);           // mudamos todos los elementos viejos al nuevo bloque
      delete[] v.mem;                        // liberamos el viejo bloque
      v.mem = nuevo;                         // apuntamos al nuevo bloque
      v.cap *= 2;                            // anunciamos que nuestra capacidad se duplicó
   }

   v.mem[v.tam] = agregar;                   // ya hay espacio, guardamos el nuevo elemento
   v.tam += 1;                               // anunciamos que ya tenemos un nuevo elemento
}

int main( )
{
   mi_vector<double> v;          // T = double
   push_back(v, 3.14);           // usé una función "libre" en lugar de una función "miembro", por eso la sintaxis es diferente; recuerden que
   push_back(v, 2.71);           // esto es sólo un ejemplo, prefieran usar el vector de la biblioteca
   push_back(v, 6.66);
   push_back(v, 0.12);
   push_back(v, 4.56);

   for (int i = 0; i < v.tam; ++i) {
      cout << v.mem[i] << " ";
   }
   cout << "\n";
   cout << "tam: " << v.tam << "\n";
   cout << "capacidad: " << v.cap << "\n";
}
