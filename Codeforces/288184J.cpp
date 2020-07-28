
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <climits>
 
using ll = long long;
struct destino{
   ll id;
   ll costo;
};
 
bool operator<(const destino& a, const destino& b){
   return a.costo > b.costo;
}
int main() {
   std::string s1, s2;
   std::cin >> s1 >> s2;
 
   ll n;  std::cin >> n;
   std::vector<destino> letras[26];
   for( ll i = 0 ; i < n ; ++i ){
      char a, b; ll valor;
      std::cin >> a; getchar(); std::cin >> b;
      std::cin >> valor; getchar();
      letras[a - 'a'].push_back({b - 'a', valor});
   }
 
   if( s1.size() != s2.size() ){
      std::cout << "-1";
      return 0;
   }
 
   ll costo[26][26];
   std::fill_n(&costo[0][0], 26*26, INT_MAX);
   std::priority_queue<destino> monticulo;
 
   for( ll i = 0 ; i < 26 ; ++i ){
 
      monticulo.push({i, 0});
      do {
         auto actual = monticulo.top();
         monticulo.pop();
         if( costo[i][actual.id] == INT_MAX ) {
            costo[i][actual.id] = actual.costo;
            for( auto vecino : letras[actual.id] ){
               monticulo.push({ vecino.id, actual.costo + vecino.costo });
            }
         }
      } while( !monticulo.empty() );
   }
   /*
   std::cout << "   ";
   for( ll i = 0 ; i < 26 ; ++i ){
      std::cout << char(i + 'a')<<": ";
   }std::cout << "\n";
   for( ll i = 0 ; i < 26 ; ++i ){
      std::cout << char(i + 'a')<<": ";
      for( ll j = 0 ; j < 26 ; ++j){
         std::cout << (costo[i][j] == INT_MAX ? -1 : costo[i][j]) << " ";
      }std::cout << "\n";
   }
*/
   ll res = 0;
   std::string solucion;
   for( ll i = 0 ; i < s1.size() ; ++i ){
      ll minimo = std::min( costo[s1[i]-'a'][s2[i]-'a'], costo[s2[i]-'a'][s1[i]-'a'] );
 
      if( minimo == INT_MAX ){
         std::cout << "-1";
         return 0;
      }
      res+= minimo;
 
      if(costo[s1[i]-'a'][s2[i]-'a'] <= costo[s2[i]-'a'][s1[i]-'a'] ){
         solucion.push_back(s2[i]);
      }else{
         solucion.push_back(s1[i]);
      }
   }
   std::cout << res << "\n" << solucion;
}
