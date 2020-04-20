#include <bits/stdc++.h>

using namespace std;

struct minion {
    int prev, d;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n);
    int x, y;
    for(int i=1; i<n; ++i) {
        cin >> x >> y; x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int dp[2][n], dd[n];
    vector< vector<minion> > loc(n);
    for(int i=0; i<n; ++i) {
        loc[i].push_back({ -1 , i });
        cin >> dp[0][i];
        dd[i] = dp[0][i];
    }
    int *ant = dp[0];
    int *sig = dp[1];
    for(int i=1; i<=k; ++i) { 
        for(int j=0; j<n; ++j ) {
            sig[j] = ant[j];
            vector<minion> tmp;
            for(int l=0; l<loc[j].size(); ++l ) {
                minion v = loc[j][l];
                for(int r=0; r<adj[v.d].size(); ++r) {
                    if( adj[v.d][r] != v.prev ) {
                        sig[j] += dd[ adj[v.d][r] ];
                        tmp.push_back( { v.d, adj[v.d][r] } );
                    }
                }
            }
            loc[j].swap(tmp);
        }
        swap(ant,sig);
    }
    for(int i=0; i<n; ++i) {
        cout << ant[i] << '\n';
    }
    return 0;
}