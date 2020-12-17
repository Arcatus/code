#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> factorials(10);
    factorials[0] = factorials[1] = 1;
    for(int i = 2; i < 10; ++i ) {
        factorials[i] = i*factorials[i - 1];
    }
    int ans = 0;
    while(n > 0) {
        for(int i = 9; i >= 0; i--) {
            if(factorials[i] <= n) {
                ans++;
                n -= factorials[i]; break;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}