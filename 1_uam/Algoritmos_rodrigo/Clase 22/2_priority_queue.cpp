// Este programa hace uso de los objetos función de la biblioteca estándar de C++ para ajustar el comportamiento de priority_queue
// El tipo de dato priority_queue implementa un montículo y usa una estructura tipo arreglo como almacenamiento subyacente, pero como se necesita usar memoria dinámica
// para hacer espacio para sus elementos, priority_queue<T> internamente usa vector<T> por omisión.
// El tipo de dato priority_queue también usa un comparador para acomodar sus elementos. Por omisión se usa less<T>, de modo que sus elementos más pequeños tienden a quedar en las hojas
// y el elemento más grande queda en la cima del montículo. Si se usa greater<T> entonces sus elementos más grandes quedan en las hojas y el elemento más pequeño queda en la cima.
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

template<typename T>
using max_heap = priority_queue<T, vector<T>, less<T>>;           // un "typedef" paramétrico, un montículo máximo usará less<T> (sus elementos más pequeños en las hojas)

template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;        // un "typedef" paramétrico, un montículo mínimo usará greater<T> (sus elementos más grandes en las hojas)

template<typename T>
void imprime(T monticulo)
{
   cout << "Los elementos van saliendo del monticulo en el orden: ";
   while (!monticulo.empty( )) {
      cout << monticulo.top( ) << " ";
      monticulo.pop( );
   }
   cout << "\n";
}

int main( )
{
   max_heap<int> monticulo_maximo;
   monticulo_maximo.push(3);
   monticulo_maximo.push(7);
   monticulo_maximo.push(5);
   monticulo_maximo.push(2);
   monticulo_maximo.push(4);
   imprime(monticulo_maximo);

   min_heap<int> monticulo_minimo;
   monticulo_minimo.push(3);
   monticulo_minimo.push(7);
   monticulo_minimo.push(5);
   monticulo_minimo.push(2);
   monticulo_minimo.push(4);
   imprime(monticulo_minimo);
}
