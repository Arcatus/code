#include <bits/stdc++.h>

using namespace std;

bool isPrime(int k) {
     if (k == 1) return false;
     else if (k % 2 == 0) {
          return k == 2 ? true : false;
     }
     for(int i = 3; i*i <= k; i+=2) {
     	if (k % i == 0) {
     	     return false;
     	}
     }
     return true;
}

int main() 
{
     ios::sync_with_stdio(false);
     cin.tie(0);
     int n;
     cin >> n;
     for(int m = 1; m <= 1000; ++m) {
          if( !isPrime(n*m + 1) ) {
               cout << m << '\n';
               return 0;
          }
     }
     return 0;
}
