#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll n, m, k;
bool visited[3][3];
bool isValid(ll f, ll c, ll y, ll x) {
    if ( c == x ) {
        //cerr << "case 1:\n";
        for(ll i=min(f,y)+1; i<=max(f,y)-1; ++i) {
            //cerr << i << " " << x << '\n';
            if ( !visited[i][x] ) {
                return false;
            }
        }
    } else if ( f == y ) {
        //cerr << "case 2:\n";
        for(ll i=min(x,c)+1; i<=max(x,c)-1; ++i) {
            //cerr << f << " " << i << '\n';
            if ( !visited[f][i] ) {
                return false;
            }
        }
    } else if ( f+c == x+y ) {
        //cerr << "case 3:\n";
        ll inc = max(x,c);
        for(ll i=min(f,y)+1; i<=max(f,y)-1; i++) {
            //cerr << i << " " << inc-1 << '\n';
            if ( !visited[i][--inc] ) {
                return false;
            }
        }
    } else if ( f-c+n-1 == y-x+n-1 ) {
        //cerr << "case 4:\n";
        ll inc = min(x,c);
        for(ll i=min(f,y)+1; i<=max(f,y)-1; i++) {
            //cerr << i << " " << inc+1 << '\n';
            if ( !visited[i][++inc] ) {
                return false;
            }
        }
    }
    return true;
}
ll solve(ll i, ll j, ll p) {
    if ( p == k ) {
        return 1;
    }
    ll ans = 0;
    for(ll y=0; y<n; ++y) {
        for(ll x=0; x<m; ++x) {
            if( !visited[y][x] && isValid(i,j,y,x) ) {
                visited[y][x] = true;
                ans += solve(y,x,p+1);
                visited[y][x] = false;
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c = 1;
    while(cin >> n >> m) {
        if(n==0&&m==0) break;
        ll ans = 0;
        for(ll i=0; i<n; ++i) {
            for(ll j=0; j<m; ++j) {
                for(k=1; k<=n*m; ++k) {
                    visited[i][j] = true;
                    ans += solve(i,j,1);
                    visited[i][j] = false;
                }
            }
        }
        cout <<"Case #" << c++ << ": " <<  ans << '\n';
    }
    return 0;
}