#include <bits/stdc++.h>

using namespace std;
using ll = long long;
/*
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}
*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    /*
    ll ans = 0, t;
    for(int i=1; i<=n; ++i) {
        t = i;
        for(int j=i+1; j<=n; ++j) {
            t = gcd(t,j);
        }
        ans += t;
        //cerr << ans << '\n';
    }
    */
    cout << 1 + 2*(n-1) << '\n';
    return 0;
}