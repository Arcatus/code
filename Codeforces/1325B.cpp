#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int n;
    while(t--) {
        cin >> n;
        set<int> p;
        int ans = 0;
        int x;
        for(int i=0; i<n; ++i) {
            cin >> x;
            auto[a, b] = p.insert(x);
            if ( b ) ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}