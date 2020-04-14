#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, c;
        cin >> n >> c;
        int pos[n];
        for(int i=0; i<n; ++i) cin >> pos[i];
        sort(pos,pos+n);
        int lo=1e9, hi = pos[n-1] - pos[0];
        for(int i = 1; i<n; ++i) {
            lo = min(lo, pos[i]-pos[i-1] );
        }
        int m, r;
        while( lo != hi ) {
            r = c;
            m = lo + (hi-lo)/2+1;
            vector<int> v(c+1);
            v[0] = pos[0]; r--;
            int k = 0, i = 0;
            while( r > 0 && k < n ) {
                while( k < n && v[i] + m > pos[k+1] ) {
                    k++;
                }
                k++;
                if ( k < n ) {            
                    i++; r--; 
                    v[i] = pos[k];
                }
            }
            if ( r == 0 ) {
                lo = m;
            } else {
                hi = m-1;
            }
        }
        cout << lo << '\n';
    }
    return 0;
}