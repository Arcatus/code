#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    char m[n+1][n+1];
    int cnt[n+1][n+1];
    char c;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            cin >> c;
            m[i][j] = c;
            cnt[i][j] = 0;
        }
    }
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            bool ok = true;
            if ( j + (k-1) < n  ) {
                for(int r=0; r<k; ++r) {
                    if( m[i][j+r] != '.' ) {
                        ok = false;
                        break;
                    }
                }
                if ( ok ) {
                    for(int r=0; r<k; ++r) {
                        cnt[i][j+r]++;
                    }      
                }
            }
            ok = true;
            if ( i + (k-1) < n ) {
                for(int r=0; r<k; ++r) {
                    if ( m[i+r][j] != '.' ) {
                        ok = false;
                        break;
                    }
                }
                if ( ok ) {
                    for(int r=0; r<k; ++r) {
                        cnt[i+r][j]++;
                    }      
                }
            }
        }
    }
    int v = -1;
    pair<int,int> ans = {1,1};
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            //cerr << cnt[i][j] << " ";
            if ( cnt[i][j] > v ) {
                v = cnt[i][j];
                ans = { i+1, j+1 };
            }
        }
        //cerr << "\n";
    }
    cout << ans.first << " " << ans.second << '\n';
    return 0;
}