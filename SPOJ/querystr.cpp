#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, n, m;
    cin >> t;   
    string s;
    while(t--) {
        cin >> s >> m;
        int n = s.size();
        reverse(s.begin(), s.end());
        int z[n] = { };
        z[0] = n;
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
        reverse(z,z+n);
        int x;
        for(int i=0; i<m; ++i) {
            cin >> x;
            cout << z[x-1] << '\n';
        }
    }
    return 0;
}