#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    ll n, k;
    while(t--) {
        cin >> n >> k;
        cout << k*(n/k) + min( n - k*(n/k), k/2) << '\n';
    }
    return 0;
}