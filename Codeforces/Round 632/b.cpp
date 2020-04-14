#include <bits/stdc++.h>

using namespace std;

string operator*(string a, const int& b) { string ans = ""; for(int i=0; i<b; ++i) ans+=a; return ans; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if (n==1) {
            int x, y;
            cin >> x >> y;
            if ( y%x == 0 ) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
        int a[n], b[n];
        for(int i=0; i<n; ++i) cin >> a[i];
        for(int i=0; i<n; ++i) cin >> b[i];
        bool pos=false, neg=false;
        for(int i=0; i<n; ++i) {
            if (a[i] > 0 ) pos=true;
            if (a[i] < 0 ) neg=true;
            if (pos && neg) break;
        }

    }
    return 0;
}