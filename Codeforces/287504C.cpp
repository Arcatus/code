#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const ll mod = 1000000007;
int main() 
{
     ios::sync_with_stdio(false);
     cin.tie(0);
     int n, p;
     cin >> n >> p;
     string s;
     cin >> s;
     bool ok = false;
     for(int i = 0; i < n - p; ++i) {
          if (s[i] == '.' || s[i] != s[i + p]) {
               ok = true;
               break;
          }
     }
     if (!ok) {
          cout << "No\n";
          return 0;
     }
     char ans[n+1];
     for(int i = 0; i < n - p; ++i) {
          if (s[i] == '.'  && s[i + p] == '.') {
               ans[i] = '1';
               ans[i + p] = '0';
          } else if (s[i] == '1' && s[i + p] == '.' ) {
               ans[i] = '1';
               ans[i + p] = '0';
          } else if (s[i] == '.' && s[i + p] == '1') {
               ans[i] = '0';
               ans[i + p] = '1';
          } else if (s[i] == '0' && s[i + p] == '.' ) {
               ans[i] = '0';
               ans[i + p] = '1';
          } else if (s[i] == '.' && s[i + p] == '0') {
               ans[i] = '1';
               ans[i + p] = '0';
          } else {
               ans[i] = s[i];
               ans[i + p] = s[i + p];
          }
     }
     for(int i = n - p; i < n; ++i) {
          if (ans[i] == '0' || ans[i] == '1') {
          } else {
               ans[i] = ((s[i]=='.')?'0':s[i]);
          }
     }
     cout << ans << '\n';
     return 0;
}
