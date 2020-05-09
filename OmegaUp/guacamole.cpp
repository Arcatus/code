#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m, t;
    cin >> n >> m >> t;
    ll I[n][m];
    for(ll i=0; i<n; ++i) {
        for(ll j=0; j<m; ++j) {
            cin >> I[i][j];
        }
    }
    ll S[n][m];
    for(ll i=0; i<n; ++i) {
        for(ll j=0; j<m; ++j) {
            cin >> S[i][j];
        }
    }
    ll P[n][m];
    for(ll i=0; i<n; ++i) {
        for(ll j=0; j<m; ++j) {
            cin >> P[i][j];
        }
    }
    function<bool(ll, ll, ll)> haytopo = [](ll t, ll ini, ll times) {
        if ( t < ini ) return false;
        return ((t - ini) % times == 0);
    };
    int dy[] = {1,1,0,-1,-1,-1, 0, 1};
    int dx[] = {0,1,1, 1, 0,-1,-1,-1};
    
    vector<vector<ll>> actual(n, vector<ll>(m));
    vector<vector<ll>> anterior(n, vector<ll>(m));

    for(ll i=0; i<n; ++i) {
        for(ll j=0; j<m; ++j) {
            if ( haytopo(1, I[i][j], S[i][j]) ) {
                actual[i][j] = P[i][j];
            }
        }
    }
    actual.swap(anterior);
    for(ll k=2; k<=t; ++k) {
        for(ll h=0; h<n; ++h) fill(actual[h].begin(), actual[h].end(), 0);
        for(ll i=0; i<n; ++i) {
            for(ll j=0; j<m; ++j) {
                if ( haytopo(k, I[i][j], S[i][j]) ) {
                    actual[i][j] += P[i][j];
                }
                ll mejor = 0;
                mejor = max(mejor, anterior[i][j] );
                for(ll l=0; l<8; ++l) {
                    if ( i+dy[l] < 0 || n <= i+dy[l] || j+dx[l] < 0 || m <= j+dx[l] ) continue;
                    mejor = max(mejor, anterior[i+dy[l]][j+dx[l]] );
                }
                actual[i][j] += mejor;
            }
        }
        actual.swap(anterior);
    }
    ll ans = 0;
    for(ll i=0; i<n; ++i) {
        for(ll j=0; j<m; ++j) {
            ans = max(ans, anterior[i][j]);
        }
    }
    cout << ans << '\n';
    return 0;
}