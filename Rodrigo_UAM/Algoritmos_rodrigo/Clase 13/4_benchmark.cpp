// programa que realiza pruebas de rendimiento de vector vs deque
#include <ctime>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

/*
   una forma (arcaica, pero fácil de recordar) de medir el tiempo que tarda un fragmento de código es

      auto t1 = clock( );
      // el código
      auto t2 = clock( );
      cout << double(t2 - t1) / CLOCKS_PER_SEC << "\n",
*/

int main( )
{
   {
      vector<int> v;
      auto t1 = clock( );
      for (int i = 0; i < 100000; ++i) {
         v.push_back(i);
      }
      for (int i = 0; i < 100000; ++i) {
         v.pop_back( );
      }
      auto t2 = clock( );
      cout << "agregando y quitando 100000 elementos del final de un vector: " << double(t2 - t1) / CLOCKS_PER_SEC << " segundos...\n";
   }

   {
      vector<int> v;
      auto t1 = clock( );
      for (int i = 0; i < 100000; ++i) {     // vector no proporciona push_front (es intencional: push_front en vector sería lento porque tiene que reacomodar todos los elementos)
         v.insert(v.begin( ), i);            // de todos modos, se puede simular con la función insert que sí se proporciona (en este caso, insertamos i al inicio y se recorren todos)
      }
      for (int i = 0; i < 100000; ++i) {     // vector no proporciona pop_front (es intencional: pop_front en vector sería lento porque tiene que reacomodar todos los elementos)
         v.erase(v.begin( ));                // de todos modos, se puede simular con la función erase que sí se proporciona (en este caso, eliminamos el elemento del inicio y se recorren todos)
      }
      auto t2 = clock( );
      cout << "agregando y quitando 100000 elementos del frente de un vector: " << double(t2 - t1) / CLOCKS_PER_SEC << " segundos...\n";
   }

   {
      deque<int> d;
      auto t1 = clock( );
      for (int i = 0; i < 100000; ++i) {
         d.push_back(i);
      }
      for (int i = 0; i < 100000; ++i) {
         d.pop_back( );
      }
      auto t2 = clock( );
      cout << "agregando y quitando 100000 elementos del final de un deque: " << double(t2 - t1) / CLOCKS_PER_SEC << " segundos...\n";
   }

   {
      deque<int> d;
      auto t1 = clock( );
      for (int i = 0; i < 100000; ++i) {
         d.push_front(i);                    // push_front sí es rápido en deque y por lo tanto, se proporciona
      }
      for (int i = 0; i < 100000; ++i) {
         d.pop_front( );                     // pop_front( ) sí es rápido en deque y por lo tanto, se proporciona
      }
      auto t2 = clock( );
      cout << "agregando y quitando 100000 elementos del frente de un deque: " << double(t2 - t1) / CLOCKS_PER_SEC << " segundos...\n";
   }
}
