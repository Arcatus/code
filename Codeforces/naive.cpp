
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <climits>
 
using ll = long long;
 
std::vector<ll> cuadrados;
void resuelve(){
   ll a, b;
   std::cin >> a >> b;
 
   std::cout << std::lower_bound(cuadrados.begin(), cuadrados.end(), b ) - std::lower_bound(cuadrados.begin(), cuadrados.end(), a )
   << "\n";
}
int main() {
   ll valor = 2;
   ll max = 10e13;
   cuadrados.push_back(1);
   while(true){
      if( valor*valor <= max){
         cuadrados.push_back(valor*valor);
         valor+=1;
      }else{
         break;
      }
   }
 
   ll t;
   std::cin >> t;
   for( int i = 0 ; i < t ; ++i){
      resuelve();
   }
}
