#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int pat[255] = { }; // 65 - 122
    int cuenta[255] = { };
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    for(int i=0; i<n; ++i) {
        pat[a[i]]++;
    }
    bool ok;
    int ans = 0;
    for(int j=0; j<n; ++j) {
        cuenta[b[j]]++;
    }
    ok = true;
    for(int j=65; j<=122; ++j) {
        if ( pat[j] != cuenta[j] ) {
            ok = false; break;
        }
    }
    if(ok) ans++;
    for(int i=1; i<=m-n; ++i) {
        ok = true;
        cuenta[ b[i-1] ]--;
        cuenta[ b[i+n-1] ]++;
        for(int j=65; j<=122; ++j) {
            if ( pat[j] != cuenta[j] ) {
                ok = false; break;
            }
        }
        if (ok) ans++;        
    }
    cout << ans << '\n';
    return 0;
}