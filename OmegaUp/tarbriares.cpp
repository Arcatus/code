#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    long long a[n];
    for(int i=0; i<n; ++i) cin >> a[i];

    auto [minv, maxv] = minmax_element(a, a+n);
    cerr << *minv << " " << *maxv << '\n';
    /*
    long long ans = 1LL << 62, acc = 0;
    for(long long i=x+1, d = 1; i<x+k; ++i, d++ ) {        
        acc += (d*(k - d))*abs( a[i] - a[i-1] );
    }    
    cout << ans << '\n';
    */o
    return 0;
}