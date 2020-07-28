#include <bits/stdc++.h>

using namespace std;

int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     int t;
     cin >> t;
     long long a, b, c;
     while(t--) {
        cin >> a >> b;
        if (a == b) {
             cout << 0 << '\n';
        } else if ( a > b ) {
             c = a - b;
             if (c % 2 == 0) {
                  cout << 1 << '\n';
             } else {
                  cout << 2 << '\n';
             }
        } else {
             c = b - a;
             if (c % 2 == 1) {
                  cout << 1 << '\n';
             } else {
                  cout << 2 << '\n';
             }
        }
     }
     return 0;
}
