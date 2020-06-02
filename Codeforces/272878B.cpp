#include <bits/stdc++.h>

using namespace std;
using ll = long long;
vector<int> ans;
ll a[11], n;
vector<ll> dist;
void solve(int k, ll ant) {
    if (k<-1) return;
    if( ans.size() == 3 ) {
        for(int i=2; i>=0; i--) cout << ans[i] << ' '; cout << '\n';
        return;
    }
    solve(k-1, ant);
    if ( dist[k] < ant ) {
        ans.push_back(dist[k]);
        solve(k-1, dist[k]);
        ans.pop_back();
    }
}
set<ll> acc;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; ++i) {
        cin >> a[i];
    } 
    solve(n-1, 10000000000000000LL);
    return 0;
}