#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
struct dragon {
    int x, y;
};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int s, n;
    cin >> s >> n;
    dragon a[n];
    for(int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y;
    }
    sort(a, a + n, [](dragon a, dragon b) {
        return (a.x == b.x ? a.y > b.y : a.x < b.x );
    });
    for(int i = 0; i < n; ++i) {
        if ( s <= a[i].x) {
            cout << "NO\n";
            return 0;
        }
        s += a[i].y;
    }
    cout << "YES\n";
    return 0;
}