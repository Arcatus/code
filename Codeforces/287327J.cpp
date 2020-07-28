#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct cliente {
     ll p, vi;
};

int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     ll n, d, a, b;
     cin >> n >> d >> a >> b;
     cliente c[n];
     ll xi, yi;
     for(int i = 0; i < n; ++i) {
          cin >> xi >> yi;
          c[i].p = i + 1;
          c[i].vi = xi*a + yi*b;
     }
     sort(c, c + n, [](cliente a, cliente b) {
          return a.vi == b.vi ? (a.p < b.p) : (a.vi < b.vi);
     });
     ll ans = 0, k = 0;
     vector<ll> pos;
     while(d and k < n ) {
     	  if ( d >= c[k].vi) {
     	       d -= c[k].vi;
     	       ans++;
               pos.push_back(c[k].p);
               k++;
     	  } else {
     	       break;
     	  }
     }
     cout << ans << '\n';
     for(ll i: pos) {
          cout << i << ' ';
     }
     cout << '\n';
     return 0;
}
