#include <bits/stdc++.h>

using namespace std;

int main()
{
     ios::sync_with_stdio(false);
     cin.tie(0);
     string s;
     cin >> s;
     int n = (int)s.size();
     string k("hello");
     for(int i = 0, j = 0; i < n; ++i) {
          if (s[i] == k[j]) {
               j++;
               if (j == 5) {
                    cout << "YES\n";               
                    return 0;
               }
          }
     }
     cout << "NO\n";
     return 0;
}
