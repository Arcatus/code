#include <bits/stdc++.h>

using namespace std;

struct inter {
    int s, e;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    inter a[n];
    for(int i=0; i<n; ++i) {
        cin >> a[i].s >> a[i].e;
    }
    vector<int> cnt;
    for(int i=1; i<= m; ++i) {
        bool ans = true;
        for(int j=0; j<n; ++j) {
            if ( a[j].s <= i && i <= a[j].e ) {
                ans = false;
                break;
            }
        }
        if ( ans ) {
            cnt.push_back(i);
        }
    }
    cout << cnt.size() << '\n';
    if ( cnt.size() > 0 ) {
        for(int k: cnt) cout << k << ' '; cout << '\n';
    }
    return 0;
}