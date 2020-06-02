#include <bits/stdc++.h>
 
using namespace std;
 
int n, a, b, c;
int memoria[4001];
int solve(int k) {
    if ( memoria[k] != -1) {
        return memoria[k];
    } else if (k == 0) {
        memoria[k] = 0;
        return memoria[k];
    }
    int x=-10000, y=-10000, z=-10000;
    if ( k >= a ) x = 1 + solve(k-a);
    if ( k >= b ) y = 1 + solve(k-b);
    if ( k >= c ) z = 1 + solve(k-c);
    memoria[k] = max(x,max(y,z));
    return memoria[k];
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> a >> b >> c;
    for(int i=0; i<=4000; ++i) {
        memoria[i] = -1;
    }
    int ans = 0;
    ans = solve(n);
    cout << ans << '\n';
    return 0;
}