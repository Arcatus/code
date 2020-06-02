#include <bits/stdc++.h>

using namespace std;
using ll = int;
ll m, n, x, p;
string C, S;
vector<int> z_algorithm(string pattern, string s) {
    s = pattern+"|"+s;
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i=1; i<n; ++i) {
        if ( i > r ) {
            l = i, r = i;
            while( r < n && s[r-l] == s[r] ) r++;
            z[i] = r - l; r--;
        } else {
            int k = i - l;
            if ( z[k] < r - i + 1 ) {
                z[i] = z[k];
            } else {
                l = i;
                while( r < n && s[r-l] == s[r] ) r++;
                z[i] = r - l; r--;
            }
        }
    }
    return z;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> C >> n >> S >> x >> p;
    ll hc = 0, hs = 0;
    for(int i=0; i<n; i++) {
        hc = (hc*x + C[i]) % p;
        hs = (hs*x + S[i]) % p;
    }
    ll d = 1;
    for(int i=0; i<n-1; ++i) {
        d = (d*x)%p;
    }
    ll cnt = 0;
    ll colisiones = 0;
    for(int i=0; i<=m-n; i++) {
        if ( hc == hs ) {
            colisiones++;
        }
        hc = (x*( hc - C[i]*d ) + C[i+n])%p;
        if (hc < 0) hc = hc + p;
    }
    vector<int> positions = z_algorithm(S,C);
    for(int i=0; i<=m-n; ++i ) {
        if ( positions[n+i+1] == n ) {
            cnt++;
        }
    }
    cout << colisiones << " " << cnt << '\n';
    return 0;
}