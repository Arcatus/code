#include <bits/stdc++.h>

using namespace std;

int pref[26+1][n+1];

int sum(int c, int l, int r) {
    return pref[c][r+1] - pref[c][l];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int n;
    while(t--)
    {
        cin >> n;
        int a[n];
        for(int i=0; i<n; ++i ) cin >> a[i];
        memset(pref, 0, sizeof pref);
        for(int i=1; i<=26; ++i) {
            for(int j=0; j<n; ++j) {
                if ( a[j] == i ) {
                    pref[i][j]++;
                }
                pref[i][j] = pref[i][j] + pref[i][j-1];
            }
        }
        int ans = 0;
        for(int i=0; i<=26; ++i) {
            ans = max(ans, pref[i][n-1]);
        }

    }
    return 0;
}