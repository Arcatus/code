#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, x;
    cin >> n >> m;
    int a[n+1];
    for(int i=0; i<n; ++i) cin >> a[i];    
    int b[m+1];
    for(int i=0; i<m; ++i) cin >> b[i];
    vector<bool> check(m+1,false);
    int ans = 0;
    for(int i=0; i<n; ++i) {
        int x = lower_bound(b, b+m, a[i]) - b;
        if ( x != m ) {
            while( check[x] == true ) {
                x++;
            }
            if (x < m) check[x] = true;
            else ans++;
        } else {
            ans++;
        } 
    }   
    cout << ans << '\n';
    return 0;
}