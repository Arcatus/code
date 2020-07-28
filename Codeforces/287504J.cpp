#include <iostream>
 
int main(){
 
   unsigned long long n, k;
   std::cin >> n >> k;
 
   if ( n == 1 ){
      std::cout << "0";
      return 0;
   }
   if( k >= n ){
      std::cout << "1";
      return 0;
   }
   unsigned long long suma = k*(k - 1)/2 + 1;
   if( suma < n ){
      std::cout << "-1";
      return 0;
   }
   unsigned long long tuberias = 1, contador = 0;
 
   do{
      if( k < 2 ){
         std::cout <<"-1";
         return 0;
      }
      if( tuberias + k - 1 <= n ){
         tuberias+=k-1;
         contador+=1;
         k-=1;
      }else{
         k = n - tuberias + 1;
      }
   }while(tuberias != n);
   std::cout << contador;
}
