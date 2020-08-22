#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct team {
    int x, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    team a[n];
    for(int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y;
    }
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if ( a[i].x == a[j].y ) {
                ans++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}