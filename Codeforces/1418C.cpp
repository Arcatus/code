#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
vector<bool> a; int n;
int memoria[2000000 + 3][2];
int solve(int i, bool j) {
    if(i >= n) return 0;
    if(memoria[i][j] != -1) return memoria[i][j];
    if(j) {
        memoria[i][j] = min(solve(i + 1, !j), solve(i + 2, !j));
    } else {
        memoria[i][j] = min(solve(i + 1, !j) + a[i], solve(i + 2, !j) + a[i] + a[i + 1]);
    }
    return memoria[i][j];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t; bool x;
    while(t--) {
        cin >> n;
        a.resize(n);
        for(int i = 0; i < n; ++i) {
            cin >> x;
            a[i] = x;
        }
        for(int i = 0; i <= n; ++i) {
            memoria[i][1] = memoria[i][0] = -1;
        }
        int ans = solve(0, 0);
        cout << ans << '\n';
    }
    return 0;
}