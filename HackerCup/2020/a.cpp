#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, k = 1;
    cin >> t;
    int n;
    string i_in, o_out;
    while(t--) {
        cin >> n;
        cin >> i_in >> o_out;
        vector<int> adj[n];
        for(int i = 0; i < n - 1; ++i) {
            if( i_in[i] == 'Y' && o_out[i + 1] == 'Y') {
                adj[i + 1].push_back(i);
            }
            if( i_in[i + 1] == 'Y' && o_out[i] == 'Y') {
                adj[i].push_back(i + 1);
            }
        }
        bool visited[n] = { };
        function<bool(int k, int j)> dfs = [&](int k, int j) {
            if (k == j) {
                return true;
            }
            visited[k] = true;
            bool ans = false;
            for(int i: adj[k]) {
                if (!visited[i] && !ans) {
                    ans = ans || dfs(i, j);
                }
            }
            return ans;
        };
        cout << "Case #" << k++ << ": \n";
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                cout <<  (dfs(i, j) ? 'Y' : 'N');
                memset(visited, false, sizeof visited);
            }
            cout << '\n';
        }
    }
    return 0;
}