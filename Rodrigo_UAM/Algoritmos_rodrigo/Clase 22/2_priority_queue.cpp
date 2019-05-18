// Este programa hace uso de los objetos funci�n de la biblioteca est�ndar de C++ para ajustar el comportamiento de priority_queue
// El tipo de dato priority_queue implementa un mont�culo y usa una estructura tipo arreglo como almacenamiento subyacente, pero como se necesita usar memoria din�mica
// para hacer espacio para sus elementos, priority_queue<T> internamente usa vector<T> por omisi�n.
// El tipo de dato priority_queue tambi�n usa un comparador para acomodar sus elementos. Por omisi�n se usa less<T>, de modo que sus elementos m�s peque�os tienden a quedar en las hojas
// y el elemento m�s grande queda en la cima del mont�culo. Si se usa greater<T> entonces sus elementos m�s grandes quedan en las hojas y el elemento m�s peque�o queda en la cima.
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

template<typename T>
using max_heap = priority_queue<T, vector<T>, less<T>>;           // un "typedef" param�trico, un mont�culo m�ximo usar� less<T> (sus elementos m�s peque�os en las hojas)

template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;        // un "typedef" param�trico, un mont�culo m�nimo usar� greater<T> (sus elementos m�s grandes en las hojas)

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
