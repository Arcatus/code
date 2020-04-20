#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int n, x;
    while (t--) {
        cin >> n;
        int cnt[n+5]={};
        for(int i=0; i<n; ++i) {
            cin >> x;
            cnt[x]++;
        }
        if ( n == 1) {
            cout << 0 << '\n';
            continue;
        }
        int v=-1, idx=-1;
        for(int i=1; i<=n; ++i) {
            if ( cnt[i] > v ) {
                idx = i;
                v = cnt[i];
            }
        }
        int diff = 0;
        for(int i=1; i<=n; ++i ) {
            if ( cnt[i] != 0 && i!=idx ) diff++;
        }
        if ( diff >= v ) {
            cout << v << '\n';
        } else {
            int lo = 1, hi = v-1;
            while( lo != hi ) {
                int m = lo + (hi-lo)/2+1;
                diff = 0;
                for(int i=1; i<=n; ++i ) {
                    if ( cnt[i] != 0 ) diff++;
                }
                if ( diff >= m ) {
                    lo = m;
                } else {
                    hi = m - 1;
                }
            }
            cout << lo << '\n';
        }
    }
    return 0;
}