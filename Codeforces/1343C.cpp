#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline ll signum(ll k) {
    return (k>0) - (k<0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    ll n;
    while(t--) {
        cin >> n;
        ll x;
        ll ans = 0, ant;
        cin >> ant;
        for(ll i=1; i<n; ++i) {
            cin >> x;
            if ( signum(ant) == signum(x) ) {
                ant = max(ant,x);
            } else {
                ans += ant;
                ant = x;
            }
        }
        ans += ant;
        cout << ans << '\n';
    }
    return 0;
}