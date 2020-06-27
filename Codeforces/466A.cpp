#include <bits/stdc++.h>

using namespace std;
int n, m, a, b;
int memoria[1001];
int solve(int k) {
    if(k >= n) return 0;    
    else if (memoria[k]!=-1) return memoria[k];
    memoria[k] = min(a+solve(k+1), b+solve(k+m));
    return memoria[k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> a >> b;
    memset(memoria, -1, sizeof memoria);
    int ans = solve(0);
    cout << ans << '\n';
    return 0;
}