#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll n;
ll h_0[100000+5], h_1[100000+5];
ll memoria[100000 + 5][3];
ll solve(int i, int k) {
     if (i == n) return 0;
     if (memoria[i][k] != -1) return memoria[i][k];
     ll tmp1 = 0, tmp2 = 0, tmp3 = 0;
     if (k == 0) {
          tmp1 = max(max(h_0[i] + solve(i + 1, 1), h_1[i] + solve(i + 1, 2) ), solve(i + 1, 0));
     } else if (k == 1) {
          tmp2 = max(h_1[i] + solve(i + 1, 2), solve(i + 1, 0));
     } else {
          tmp3 = max(h_0[i] + solve(i + 1, 1), solve(i + 1, 0));
     }
     memoria[i][k] = max(max(tmp1, tmp2), tmp3);
     return memoria[i][k];
}

int main() 
{
     ios::sync_with_stdio(false);
     cin.tie(0);
     cin >> n;
     for(int i = 0; i < n; ++i) cin >> h_0[i];
     for(int i = 0; i < n; ++i) cin >> h_1[i];
     memset(memoria, -1, sizeof memoria);
     ll ans = solve(0, 0);
     cout << ans << '\n';
     return 0;
}
