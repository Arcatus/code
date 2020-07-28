#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
int main() {
     int t;
     cin >> t;
     ll a, b;
     while(t--) {
          cin >> a >> b;
          if (a == b) {
               if(sqrt(a) - floor(sqrt(a)) == 0) {
                    cout << 1 << '\n';
               } else {
                    cout << 0 << '\n';
               }
          } else {
               cout << int(floor(sqrt(b)+1) - ceil(sqrt(a))) << '\n';
          }
     }
     return 0;
}
