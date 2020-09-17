#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    ll x, y, k;
    while(t--) {
        cin >> x >> y >> k;
        ll cnt = (k + y*k - 1LL)/(x - 1LL);
        if((k + y*k - 1) % (x - 1) != 0) cnt++;
        cout << cnt + k << '\n';
    }   
    return 0;
}