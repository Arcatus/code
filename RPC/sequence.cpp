#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    ll s;
    while(t--) {
        cin >> s;
        cout << (s + 1LL)*(s + 1LL) - 1LL << '\n';
    }
    return 0;
}