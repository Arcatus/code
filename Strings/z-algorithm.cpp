#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    int z[n] = { };
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
    return 0;
}