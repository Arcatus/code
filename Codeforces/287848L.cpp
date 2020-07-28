#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     ll a, b, w, x, c, df;
     cin >> a >> b >> w >> x >> c;
     ll sec = 1, deca = 0;
     while(a < c) {
          cerr << sec << '\n';
          if(b >= x) {
               df = ((b - x) / x) + 1;
               b -= x*df;
               sec += df;
     	  } else {
	       df = (x - b) / (w - x) + ((x - b) % (w - x));
	       b += df*(w - x);
	       deca += df;
	       cerr << "deca; " << deca << '\n';
	       sec += df;
	       cerr << "sec: " << sec;
	       cerr << " c value: " << (c - sec) << " a value: " << (a - deca) << '\n';
	       if(c - sec < a - deca ) {
	            cout << "ans: " << sec - (abs(a - deca) - abs(c - sec) + 1) << '\n';
	            return 0;
	       }
     	  }
     }
     cout << 0 << '\n';
     return 0;
}
