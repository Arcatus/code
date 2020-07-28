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
    int bkt[1000000 + 1] = { };
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
    for(int i = 0; i < n; ++i) {
        if (i + z[i] == n) {
            int tmp = z[i];
            while(tmp) {
                bkt[tmp]++;
                tmp--;
            }
        } else {
            bkt[z[i]]++;
        }
    }
    for(int i = n - 1; i >= 1; i--) {
        if (bkt[i] >= 2) {
            for(int j = 0; j < i; ++j) {
                cout << s[j];
            }
            cout << '\n';
            return 0;
        }
    }
    cout << "Just a legend\n";
    return 0;
}