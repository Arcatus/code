#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll a[100001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, h, b, r=1LL<<60;
    cin >> n >> h >> b;
    for(ll i=0; i<n; ++i) {
        cin >> a[i];
        if ( a[i] >= h ) {
            r = min(r, a[i]);
        }
    }
    ll costo = 0;
    ll cnt = 0;
    for(ll i=0; i<n; ++i) {
        if ( a[i] < r ) {
            cnt = 0;
            costo += (i+1)*(r - a[i]);
        } else cnt++;
        if (cnt == b) {
            cout << '0' << '\n';
            return 0;
        }
    }
    cout << costo << '\n';
    return 0;
}