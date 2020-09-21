#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll inf = 10000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    if(a.size() != b.size()) {
        cout << -1 << '\n';
        return 0;
    }
    ll n;
    cin >> n;
    ll P[26][26] = { };
    for(ll i = 0; i < 26; ++i) 
        for(ll j = 0; j < 26; ++j) 
            if(i != j) P[i][j] = inf;
    ll z;
    char x, y;
    for(ll i = 0; i < n; ++i) {
        cin >> x >> y >> z;
        P[x - 'a'][y - 'a'] = min(z, P[x - 'a'][y - 'a']);
    }
    for(ll k = 0; k < 26; ++k) {
        for(ll i = 0; i < 26; ++i) {
            for(ll j = 0; j < 26; ++j) {
                if(P[i][k] + P[k][j] < P[i][j]) {
                    P[i][j] = P[i][k] + P[k][j];
                }
            }
        }
    }
    char to_change;
    ll ans = 0, best, p, q;
    for(ll i = 0; i < a.size(); ++i) {
        best = inf;
        for(int j = 0; j < 26; ++j) {
            p = P[a[i] - 'a'][j] + P[b[i] - 'a'][j];
            if(p < best) {
                best = p;
                to_change = char(j + 'a');
            }
        }
        if(best < inf) {
            ans += best;
            a[i] = to_change;
        } else {
            cout << -1 << '\n';
            return 0;
        }
    }
    cout << ans << '\n';
    cout << a << '\n';
    return 0;
}