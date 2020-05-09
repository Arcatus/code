#include <bits/stdc++.h>

using namespace std;

struct p{
 int x, y;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int x;
    p a[n*n+1];
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) {
            cin >> x;
            a[x] = { i, j };
        }
    }
    function<int(int)> myabs = [](const int& z) {
        return z < 0 ? -z : z;
    };
    int ans = 0;
    for(int i=2; i<=n*n; ++i) {
        ans += myabs( a[i].x - a[i-1].x) + myabs( a[i].y - a[i-1].y );
    } 
    cout << ans << '\n';
    return 0;
}