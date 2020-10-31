#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct par {
    ll first, second, v;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m, t;
    cin >> n >> m >> t;
    vector<string> mat(n);
    for(auto& i: mat) cin >> i;
    ll dx[4] = {1, 0, 0, -1};
    ll dy[4] = {0, 1, -1, 0};
    bool visited[n][m] = { };
    int dist[n][m] = { };
    for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j)
        dist[i][j] = INT_MAX;
    queue<par> cola;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            for(int k = 0; k < 4; ++k) {
                int ny = i + dy[k];
                int nx = j + dx[k];
                if(nx<0||nx>=m||ny<0||ny>=n) continue;
                if(mat[i][j] == mat[ny][nx]) {
                    visited[i][j]=true;
                    dist[i][j] = 0;
                    cola.push({i, j, 0});
                    break;                    
                }
            }
        }
    }
    while(!cola.empty()) {
        par p = cola.front();
        cola.pop();
        for(int k = 0; k < 4; ++k) {
            int ny = p.first + dy[k];
            int nx = p.second + dx[k];
            if(nx<0||nx>=m||ny<0||ny>=n||visited[ny][nx]) continue;
            dist[ny][nx] = dist[p.first][p.second] + 1;
            visited[ny][nx] = true;
            cola.push({ny, nx, dist[ny][nx]});
        }
    }
    ll i, j, p;
    while(t--) {
        cin >> i >> j >> p; i--; j--;
        if(p <= dist[i][j] || dist[i][j] == INT_MAX) {
            cout << mat[i][j] << '\n';
        } else {
            cout << (p - dist[i][j] + (mat[i][j]-'0')) % 2 << '\n';
        }
    }
    return 0;
}