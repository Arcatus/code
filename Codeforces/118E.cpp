#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1000000 + 1;

int low[N]; 
int apari[N];
int bridgec, cur;
vector<int> adj[N];
set<pair<int,int>> ans;

void dfs(int vertex, int parent) {
    cur++;
    low[vertex] = cur;
    apari[vertex] = cur;
    for(int i: adj[vertex]) {
        if(apari[i] == 0) {
            ans.insert({vertex, i});
            dfs(i, vertex);
            low[vertex] = min(low[vertex], low[i]);
            if(low[i] > apari[vertex]) {
                bridgec++;
            }
        } else if(i != parent) {
            if(ans.count({i, vertex}) == 0) {
                ans.insert({vertex, i});
            }
            low[vertex] = min(low[vertex], apari[i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int u, v;
    for(int i = 0; i < m; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    if(bridgec == 0) {
        auto it = ans.begin();
        while(it != ans.end()) {
            cout << it->first << " " << it->second << '\n';
            it++;
        }
    } else {
        cout << 0 << '\n';
    }
    return 0;
}