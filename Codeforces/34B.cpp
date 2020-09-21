#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int& i: a) cin >> i;
    sort(a.begin(), a.end());
    ll ans = 0;
    for(int i = 0; i < m; ++i) {
        if(a[i] >= 0) break;
        ans += (-a[i]);
    }
    cout << ans << '\n';
    return 0;
}