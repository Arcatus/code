#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    set<pair<int,int>> p;
    int x, y;
    for(int i=0; i<n; ++i) {
        cin >> x >> y;
        p.insert({x,y});
    }
    for(int i=0; i<k; ++i) {
        cin >> x >> y;
        if ( p.count({x,y}) > 0 ) {
            cout << 0 << '\n';
        } else {
            cout << 1 << '\n';
        }

    }
    return 0;
}