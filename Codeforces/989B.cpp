#include <bits/stdc++.h>

using namespace std;

int main()
{
     ios::sync_with_stdio(false);
     cin.tie(0);
     int n, p;
     cin >> n >> p;
     string s;
     cin >> s;
     bool ok = true;
     for(int i = 0; i < n - p; ++i) {
         if (s[i] != s[i + p]) {
             ok = false;         
             break;
         }
     }
     if(ok) {
         cout << "No\n";
         return 0;
     }
     for(int i = 0; i < n - p; ++i) {
         
     }
     return 0;
}
