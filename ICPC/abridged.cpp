#include <bits/stdc++.h>

using namespace std;

struct x {
    int t[2], p;
} L[200000+1];

int cmp(x a, x b) {
    return a.t[0] == b.t[0] ? ( a.t[1] < b.t[1] ? 1:0 ):( a.t[0] < b.t[0] ? 1:0 );
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;    
    while(t--) {
        int tam; string s;
        cin >> tam >> s;
        s += s;
        int n = s.size();
        int P[(int)log2(n)+5][n+5] = {};
        for(int i=0; i<n; ++i) P[0][i] = s[i] - 'a';
        for(int i=1, k=1; k < n; ++i, k<<=1 ) {
            for(int j=0; j<n; ++j) {
                L[j].t[0] = P[i-1][j];
                L[j].t[1] = j+k<n ? P[i-1][j+k] : -1;
                L[j].p = j;
            }
            sort(L, L+n, cmp);
            for(int j=0; j<n; ++j) {
                P[i][L[j].p] = j > 0 && L[j].t[0] == L[j-1].t[0] && L[j].t[1] == L[j-1].t[1] ? P[i][L[j-1].p]: j;
            }
        }
        int ans = (int)1e9, indi=-1;
        int r = (int)log2(n/2);
        for(int i=0; i<=s.size()/2; ++i) {
            if ( P[r][i] < ans ) {
                indi = i;
                ans = P[r][i];
            }
        }
        cout << indi << '\n';
    }
} 