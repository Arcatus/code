#include <bits/stdc++.h>

using namespace std;
using ll = long long;
bool sieve[1000000 + 5];
void build(ll n) {
    fill(sieve, sieve + 1000000, true);
    sieve[1] = false;
    for(ll i = 2; i*i <= n; ++i) {
        for(int j = i*i; j <= n; j+=i) {
            sieve[j] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    build(1000001);
    int x = 2, y = n - 2;
    while( x <= y && (sieve[x] || sieve[y]) ) {
        x++; y--;
    }
    cout << x << " " << y << '\n';
    return 0;
}