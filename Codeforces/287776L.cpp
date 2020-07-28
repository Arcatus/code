#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
int main() {
     int n, m;
     cin >> n >> m;
     int garden[n][m];
     for(int i = 0; i < n; ++i) {
          for(int j = 0; j < m; ++j) {
               cin >> garden[i][j];
          }
     }
     int a, b;
     cin >> a >> b;
     int ans = a*b + 1, tmp;
     if (a <= n && b <= m) {
	     for(int h = 0; h <= n - a; ++h) {
		  for(int p = 0; p <= m - b; ++p) {
		     tmp = 0;
		     for(int i = h; i < a+h; ++i) {
			  for(int j = p; j < b+p; ++j) {
			       tmp += garden[i][j];
			  }
		     }
		     ans = min(ans, tmp);
		  }
	     }
     }
     if (b <= n && a <= m) {
	     for(int h = 0; h <= n - b; ++h) {
		  for(int p = 0; p <= m - a; ++p) {
		     cerr << h << " " << p << '\n';
		     tmp = 0;
		     for(int i = h; i < b+h; ++i) {
			  for(int j = p; j < a+p; ++j) {
			       tmp += garden[i][j];
			  }
		     }
		     ans = min(ans, tmp);
		  }
	     }
     }
     cout << ans << '\n';
     return 0;
}
