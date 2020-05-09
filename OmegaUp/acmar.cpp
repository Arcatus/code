#include <bits/stdc++.h>

using namespace std;

int elements;
int degree[10000+5];
bool visitado[10000+1];
vector<vector<int>> adj(10000+5);

struct rail {
    int numel, lst;
};

void dfs(int k, int crt) {
    visitado[k] = true; 
    for(int i=0; i<adj[k].size(); ++i) {
        int v = adj[k][i];
        if ( !visitado[ v ] && v != crt ) {
            dfs(v, crt);
        }
    }
    elements++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int x, y;
    for(int i=0; i<n; ++i) {
        cin >> x >> y;
        adj[x].push_back(y);
        degree[x]++;
        degree[y]++;
    }
    int k = -1, critico;
    for(int i=0; i<=n; ++i) {
        if ( degree[i] > k ) {
            critico = i;
            k = degree[i];
        }
    }
    vector<rail> p;
    for(int i=0; i<=n; ++i) {
        if ( !visitado[i] && i != critico ) {
            elements = 0;
            dfs(i,critico);            
            p.push_back( { elements, i } );
        }
    }
    int ans1 = 0;
    for(int i=0; i<p.size()-1; ++i) {
        for(int j=i+1; j<p.size(); ++j) {
            ans1 += p[i].numel*p[j].numel;
        }
    }
    sort(p.begin(), p.end(), [](rail a, rail b) {
        return a.numel < b.numel;
    } );
    x = p[p.size()-1].lst;
    y = p[p.size()-2].lst;
    adj[x].push_back(y);
    adj[y].push_back(x);
    p.clear();
    memset(visitado, false, sizeof visitado);
    for(int i=0; i<=n; ++i) {
        if ( !visitado[i] && i != critico ) {
            elements = 0;
            dfs(i,critico);            
            p.push_back( { elements, i } );
        }
    }
    int ans2 = 0;
    for(int i=0; i<p.size()-1; ++i) {
        for(int j=i+1; j<p.size(); ++j) {
            ans2 += p[i].numel * p[j].numel;
        }
    }
    cout << ans1 << " " << ans2 << '\n';
    return 0;
}