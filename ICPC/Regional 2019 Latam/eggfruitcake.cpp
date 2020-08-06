#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int s;
    string b;
    cin >> b >> s;
    int n = b.size();
    b += b;
    vector<int> x;
    for(int i = 0; i < 2*n; ++i) {
        if (b[i] == 'E') {
            x.push_back(i);
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; ++i) {
        auto it = lower_bound(x.begin(), x.end(), i);
        if (it != x.end() && i + s >= *it) {
            ans += (ll) (i + s) - *it;
        }   
    }
    cout << ans << '\n';
    return 0;
}