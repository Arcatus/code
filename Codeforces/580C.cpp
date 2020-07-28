#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int gato[n];
    for(int i = 0; i < n; ++i) {
        cin >> gato[i];
    }
    vector<int> adj[n];
    int a, b;
    for(int i = 0; i < n - 1; ++i) {
        cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> q;
    q.push(0);
    bool visited[n];
    visited[0] = true;
    int dist[n] = { };
    memset(dist, INT_MAX, sizeof dist);
    dist[0] = gato[0];
    memset(visited, false, sizeof visited);
    while(!q.empty()) {
        int p = q.front();
        q.pop();
        for(int i : adj[p]) {
            if (!visited[i]) {
                if( gato[i] ) {
                    dist[i] = dist[p] + 1;
                } else {
                    dist[i] = 0;
                }
                if (dist[i] <= m ) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1; i < n; ++i) {
        if ( visited[i] && adj[i].size() == 1) {
            ans++;
        }
    }
    cout << ans <<'\n';
    return 0;
}