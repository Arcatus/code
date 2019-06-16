#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> adyacencia[10000+1];
vector<int> tiempoEnLLegar(10000+1, -1);

int main( )
{
   ios::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   int v, e;
   cin >> v >> e;

   for (int i = 0; i < e; ++i) {
      int x, y;
      cin >> x >> y;
      adyacencia[x].push_back(y);
      adyacencia[y].push_back(x);
   }

   int inicial = 0;

   int escape;
   
   cin >> escape;

   int posicion[escape];

   for (int i=0; i < escape; ++i)
   {
   		cin >> posicion[i];
   }

   queue<int> cola;
   cola.push(0);                         
   tiempoEnLLegar[0] = 0;                    

   do {
      int actual = cola.front( );
      cola.pop( );

      for (int vecino : adyacencia[actual]) {           
         if (tiempoEnLLegar[vecino] == -1) {                 
            tiempoEnLLegar[vecino] = tiempoEnLLegar[actual] + 1; 
            cola.push(vecino);                           
         }
      }
   } while (!cola.empty( ));

   for (int t=0; t < escape; ++t)
   {
   		int tiempoPolicia = tiempoEnLLegar[ posicion[t] ];

   		if ( tiempoPolicia <= t && tiempoPolicia != -1)
   		{
   			cout << t << '\n';
   			return 0;
   		}
   }   

   cout << "-1" << '\n';
}
