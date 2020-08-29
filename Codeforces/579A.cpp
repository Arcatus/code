#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    if (n == 1) {
        cout << 1 << '\n';
    } else {
        int bacteria = 0;
        while(n > 0) {
            n -= (1LL << int(floor( log2(n) )) );
            bacteria++;
        }
        cout << bacteria << '\n';
    }
    return 0;
}