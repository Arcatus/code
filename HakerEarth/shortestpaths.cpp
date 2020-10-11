#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = (int)1e9;
struct element {
    int vertice, costo;
};

bool operator <(element a, element b) {
    return a.costo > b.costo;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int u, v, c;
    vector<element> l[n + 1];
    for(int i = 0; i < m; ++i) {
        cin >> u >> v >> c;
        l[u - 1].push_back({v - 1, c});
        //l[v - 1].push_back({u - 1, c});
    }
    int dist[n];
    for(int i = 0; i < n; ++i) dist[i] = inf;
    priority_queue<element> q;
    q.push(element{0, 0});
    while(!q.empty()) {
        element p = q.top();
        q.pop();
        if(dist[p.vertice] == inf) {
            dist[p.vertice] = p.costo;
            for(element i: l[p.vertice]) {
                q.push(element{i.vertice, i.costo + p.costo});
            }
        }
    }
    for(int i = 1; i < n; ++i) {
        cout << dist[i] << " \n"[i == n - 1];
    }
    return 0;
}