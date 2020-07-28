#include <bits/stdc++.h>

using namespace std;
int a[200000+1];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> adjList[200000+1];
    int x, y, z;
    for(int i = 0; i < n - 1; ++i) {
        cin >> x >> y; x--; y--;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    bool visited[n];
    function<void(int, int)> dfs = [&](int k, int p) {
        a[k] += p;
        for(int i: adjList[k] ) {
            if (!visited[i]) {
                visited[i] = true;
                dfs(i, -p);
            }
        }
    };
    for(int i=0; i<m; ++i) {
        cin >> x;
        if (x == 1) {
            cin >> y >> z; y--;
            memset(visited, false, sizeof visited);
            visited[y] = true;
            dfs(y, z);
        } else {
            cin >> y; y--;
            cout << a[y] << '\n';
        }
    }
    return 0;
}