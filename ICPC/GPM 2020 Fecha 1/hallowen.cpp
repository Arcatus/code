#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int n;
int a[51], memoria[51];
ll solve(int p) {
    if(p >= n) return 0;
    else if(memoria[p] != -1) return memoria[p];
    memoria[p] = max(a[p] + solve(p + 2), solve(p + 1));
    return memoria[p];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; ++i) {
            memoria[i] = -1;
        }
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int ans = solve(0);
        cout << ans << '\n';
    }
    return 0;
}