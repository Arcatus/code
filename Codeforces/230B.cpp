#include <bits/stdc++.h>

using namespace std;
using ll = long long;
bool sieve[1000000 + 5] = { };

void build(ll n) {
    memset(sieve, true, sizeof(sieve));
    for(ll i = 2; i*i <= n; i++) {
        if(sieve[i]) {
            for(int j = i*i; j <= n; j+=i) {
                sieve[j] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, x;
    cin >> n;
    build(1000001);
    set<ll> c;    
    for(ll i = 2LL; i*i <= (ll)1e12; ++i) {
        if(sieve[i]) {
            c.insert(i*i);
        }
    }
    for(int i = 0; i < n; ++i) {
        cin >> x;
        if(c.count(x) > 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}