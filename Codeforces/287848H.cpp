#include <bits/stdc++.h>

using namespace std;

int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     string s, t;
     cin >> s >> t;
     int n = s.size();
     int m = t.size();
     if (m < n << 1) {
          cout << 0 << '\n';
     } else {
          int a = -1, b = -1;
          for(int i = 0, j = 0; i < m; ++i) {
                if (t[i] == s[j]) {
                     j++;
                     if( j == n ) {
                          a = i; break;
                     }
                }
          }
          for(int i = m - 1, j = n - 1; i >= 0; i--) {
                if (t[i] == s[j]) {
                     j--;
                     if( j == -1 ) {
                          b = i; break;
                     }
                }
          }
          if (a != -1 && a < b) {
          	cout << b - a << '\n';
          } else {
                cout << 0 << '\n';
          }
     }
     return 0;
}
