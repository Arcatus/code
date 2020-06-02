#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll solve(ll ant, ll cnt) {
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    long long a[n];
    for(int i=0; i<n; ++i) cin >> a[i];
    int lo = 0, hi = 1000000000, mid, cnt,ot=0; 
    while( lo < hi && ot < 40 ) { ot++;
        mid = lo + (hi+lo)/2;
        cerr << mid << '\n';
        cnt = 0;
        for(int i=0; i<n; ++i) {
            if ( mid - a[i] >= 0 ) {
                cnt++;
            }
        }
        cerr << "cnt: " << cnt << '\n';
        if ( cnt >= k ) {
            hi = mid;
        } else {
            lo = mid+1;
        }
    }
    cerr << lo << '\n';
    /*
    long long ans = 1LL << 62, acc = 0;
    for(long long i=x+1, d = 1; i<x+k; ++i, d++ ) {
        acc += (d*(k - d))*abs( a[i] - a[i-1] );
    }    
    cout << ans << '\n';
    */
    return 0;
}