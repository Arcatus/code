#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() 
{
     ios::sync_with_stdio(false);
     cin.tie(0);
     ll a, b, s;
     cin >> a >> b >> s;
     ll dist = abs(a) + abs(b);
     if ( dist <= s) {
          if ( s % 2 == dist % 2 ) {
               cout << "Yes\n";
          } else {
               cout << "No\n";
          }
     } else {
          cout << "No\n";
     }
     return 0;
}
