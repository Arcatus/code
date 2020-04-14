#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n; 
    vector<int> inc(n+1,0);
    vector<int> ans(n+1,0);
    int m, x, a, b;
    cin >> m;
    for(int i=0; i<m;++i) {
        char c;
        cin >> c;
        if( c == 'P' ) {
            cin >> x;
            ans = inc;
            for(int i=1; i<n; ++i) {
                ans[i] += ans[i-1];
            }
            cout << ans[x] << '\n';
        } else {
            cin >> a >> b;
            inc[a] += 1;
            inc[b] -= 1;
        }
    }
    return 0;
}