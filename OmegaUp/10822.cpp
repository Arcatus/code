#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, p;
    cin >> n >> p;
    vector<vector<int>> adj(n);
    int x, y;
    for(int i=0; i<p; ++i) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bool visited[n] = { };
    int cnt = 0;
    function<void(int)> dfs = [&](int k) {
        cnt++;
        visited[k] = 1;
        for(int i: adj[k] ) {
            if ( !visited[i] ) {
                dfs(i);
            }
        }
    };
    vector<int> v;
    for(int i=0; i<n; ++i) {
        if ( !visited[i] ) {
            cnt = 0;
            dfs(i);
            v.push_back(cnt);
            cnt = 0;
        }
    }
    if ( v.size() > 1 ) {
        int ans=1;
        for(int x : v ) {
            ans *= x;
        }
        cout << ans << '\n';
    } else {
        cout << 0 << '\n';
    }

    return 0;
}