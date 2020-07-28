#include <iostream>
#include <deque>
#include <cmath>
 
int main(){
   int n, x;
   std::cin >> n >> x;
 
   int suma = 0;
   for( int i = 0 ; i < n ; ++i){
      int valor;
      std::cin >> valor;
      suma+=valor;
   }
   int pasos = 0;
   do{
      suma = std::abs(suma);
      if( suma > 0 ){
         if ( suma <= x ){
            suma-=suma;
         }else{
            suma-=x;
         }
         pasos+=1;
      }
   }while( suma != 0 );
   std::cout << pasos;
}
