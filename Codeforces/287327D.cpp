#include <bits/stdc++.h>

using namespace std;

int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     int n, a, b, c, x;
     cin >> n >> a >> b;
     int ans = 0; c = 0;
     for(int i = 0; i < n; ++i) {
     	cin >> x;
     	if(x == 1) { 
     	     if (a > 0) {
     	          a--;
     	     } else if(b > 0) {
     	          c++;
     	          b--;
     	     } else if(c > 0) {
      	     	  c--;
     	     } else {
     	          ans++;
     	     }
     	} else {
     	     if(b > 0) {
     	     	 b--;
     	     } else {
     	         ans+=2;
     	     }
     	}
     }
     cout << ans << '\n';
     return 0;
}
